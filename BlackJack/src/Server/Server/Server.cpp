#include <iostream>
#include <server.h>

int main()
{
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Winsock initialization failed!" << std::endl;
        return 1;
    }

    // Создание сокета
    SOCKET server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == INVALID_SOCKET) {
        std::cerr << "Socket creation failed!" << std::endl;
        WSACleanup();
        return 1;
    }

    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(12345);

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        std::cerr << "Bind failed!" << std::endl;
        closesocket(server_socket);
        WSACleanup();
        return 1;
    }

    if (listen(server_socket, 2) == SOCKET_ERROR) {
        std::cerr << "Listen failed!" << std::endl;
        closesocket(server_socket);
        WSACleanup();
        return 1;
    }

    std::cout << "Server is running, waiting for players..." << std::endl;

    // Принятие подключений
    sockaddr_in client_addr;
    int client_len = sizeof(client_addr);

    SOCKET player1_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_len);
    if (player1_socket == INVALID_SOCKET) {
        std::cerr << "Failed to accept player 1!" << std::endl;
        closesocket(server_socket);
        WSACleanup();
        return 1;
    }
    std::cout << "Player 1 connected!" << std::endl;

    SOCKET player2_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_len);
    if (player2_socket == INVALID_SOCKET) {
        std::cerr << "Failed to accept player 2!" << std::endl;
        closesocket(player1_socket);
        closesocket(server_socket);
        WSACleanup();
        return 1;
    }
    std::cout << "Player 2 connected!" << std::endl;

    _ST_CARD_PLAYER::Player player1(player1_socket);
    _ST_CARD_PLAYER::Player player2(player2_socket);

    player1.is_turn = true; // Игрок 1 начинает первым

    std::vector<_ST_CARD_PLAYER::Card> deck = _ST_GLOBAL_VAL_FUNC::shuffle_deck();

    std::thread game_thread_1(_ST_GLOBAL_VAL_FUNC::thrGame, std::ref(player1), std::ref(player2), std::ref(deck));

    game_thread_1.join();

    closesocket(player1_socket);
    closesocket(player2_socket);
    closesocket(server_socket);
    WSACleanup();

    return 0;
}
