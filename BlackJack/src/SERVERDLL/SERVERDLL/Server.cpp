#include "pch.h"
#include "Server.h"

int _ST_CARD_PLAYER::Card::getValue() const
{
    if (rank == "J" || rank == "Q" || rank == "K") return 10;
    if (rank == "A") return 11;
    return stoi(rank);
}
_ST_CARD_PLAYER::Player::Player(SOCKET s) : socket(s), is_turn(0) {};
void _ST_CARD_PLAYER::Player::send_message(const std::string& message)
{
    send(socket, message.c_str(), static_cast<int>(message.size()), 0);
}
std::string _ST_CARD_PLAYER::Player::receive_message() 
{
    char buff[1024];
    int len = recv(socket, buff, sizeof(buff), 0);
    return std::string(buff, len);
}
std::vector<_ST_CARD_PLAYER::Card> _ST_GLOBAL_VAL_FUNC::shuffle_deck() 
{
    std::vector<_ST_CARD_PLAYER::Card> deck;
    for (const auto& suit : suits) {
        for (const auto& rank : ranks) {
            deck.push_back(_ST_CARD_PLAYER::Card{ rank, suit });
        }
    }
    std::random_device rd;
    std::mt19937 g(rd());
    shuffle(deck.begin(), deck.end(), g);
    return deck;
}
int _ST_GLOBAL_VAL_FUNC::calculate_score(const std::vector<_ST_CARD_PLAYER::Card>& hand)
{
    int score = 0;
    int aces = 0;
    for (const auto& card : hand) 
    {
        score += card.getValue();
        if (card.rank == "A") aces++;
    }

    while (score > 21 && aces > 0) {
        score -= 10;
        aces--;
    }

    return score;
}
void _ST_GLOBAL_VAL_FUNC::thrGame(  _ST_CARD_PLAYER::Player& player,
                                    _ST_CARD_PLAYER::Player& player2,
                                    std::vector<_ST_CARD_PLAYER::Card> deck)
{
    int deck_index = 0;
    player.hand.push_back(deck[deck_index++]);
    player2.hand.push_back(deck[deck_index++]);
    player.hand.push_back(deck[deck_index++]);
    player2.hand.push_back(deck[deck_index++]);

    bool game_over = 0;

    while (!game_over) {
        _ST_CARD_PLAYER::Player* current_player = nullptr;
        std::string message;

        if (player.is_turn) current_player = &player;
        else if (player2.is_turn) current_player = &player2;

        if (current_player) {
            int score = calculate_score(current_player->hand);
            message = "Your turn. Cards: ";
            for (const auto& card : current_player->hand) 
            {
                message += card.rank + " of " + card.suit + " ";
            }
            message += "\nYour score: " + std::to_string(score) + "\n";
            message += "Do you want to 'Hit' or 'Stand'?";

            current_player->send_message(message);
            std::string action = current_player->receive_message();

            if (action == "Hit") 
            {
                current_player->hand.push_back(deck[deck_index++]);
            }

            score = calculate_score(current_player->hand);
            if (score >= 21 || action == "Stand") 
            {
                current_player->send_message("Your turn is over.\n");
                current_player->is_turn = false;
                if (current_player == &player) 
                {
                    player2.is_turn = true;
                }
                else 
                {
                    game_over = true;
                }
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    int score1 = calculate_score(player.hand);
    int score2 = calculate_score(player2.hand);

    player.send_message("Game over. Your final score: " + std::to_string(score1) + "\n");
    player2.send_message("Game over. Your final score: " + std::to_string(score2) + "\n");

    if (score1 > 21) score1 = 0;
    if (score2 > 21) score2 = 0;

    if (score1 > score2) {
        player.send_message("You win!\n");
        player2.send_message("You lose.\n");
    }
    else if (score2 > score1) {
        player.send_message("You lose.\n");
        player2.send_message("You win!\n");
    }
    else {
        player.send_message("It's a draw.\n");
        player2.send_message("It's a draw.\n");
    }

    player.send_message("Do you want to play again? (yes/no)\n");
    player2.send_message("Do you want to play again? (yes/no)\n");

    std::string response1 = player.receive_message();
    std::string response2 = player2.receive_message();

    if (response1 == "yes" && response2 == "yes") {
        _ST_GLOBAL_VAL_FUNC::thrGame(player, player2, deck);
    }
    else {
        player.send_message("Goodbye.\n");
        player2.send_message("Goodbye.\n");
    }

}
