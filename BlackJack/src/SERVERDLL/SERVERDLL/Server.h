#pragma once
#include "config.h"

#ifdef SERVERDLL_EXPORTS
#define SERVERDLL_API __declspec(dllexport)
#else
#define SERVERDLL_API __declspec(dllimport)
#endif

namespace _ST_CARD_PLAYER
{
    struct Card 
    {
	    std::string rank;
        std::string suit;
        SERVERDLL_API int getValue() const;
    };
    struct Player {
        SOCKET socket;
        std::vector<Card> hand;
        bool is_turn;

        SERVERDLL_API Player(SOCKET s);

        SERVERDLL_API void send_message(const std::string&);

        SERVERDLL_API std::string receive_message();
    };

}
namespace _ST_GLOBAL_VAL_FUNC 
{
    std::vector<std::string> suits = { "Hearts", "Diamonds", "Clubs", "Spades" };
    std::vector<std::string> ranks = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };

    SERVERDLL_API std::vector<_ST_CARD_PLAYER::Card> shuffle_deck();
    SERVERDLL_API int calculate_score(const std::vector<_ST_CARD_PLAYER::Card>&);
    SERVERDLL_API void thrGame(   _ST_CARD_PLAYER::Player&,
                    _ST_CARD_PLAYER::Player&,
                    std::vector<_ST_CARD_PLAYER::Card>);
}