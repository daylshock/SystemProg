#include <iostream>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h> 

int main() {
    // Инициализация Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Winsock initialization failed!" << std::endl;
        return 1;
    }

    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET) {
        std::cerr << "Socket creation failed!" << std::endl;
        WSACleanup();
        return 1;
    }

    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345);

    const char* s_ip = "127.0.0.1";
    if (inet_pton(AF_INET, s_ip, &server_addr.sin_addr) <= 0) 
    {
        std::cerr << "IP invalid" << std::endl;
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        std::cerr << "Connection failed!" << std::endl;
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    while (true) {
        char buffer[1024];
        int len = recv(sock, buffer, sizeof(buffer), 0);
        std::cout.write(buffer, len);
        std::cout << std::endl;

        std::string response;
        std::getline(std::cin, response);
        send(sock, response.c_str(), response.size(), 0);
    }

    closesocket(sock);
    WSACleanup();
    return 0;
}
