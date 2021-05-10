#ifndef PLAYER_H
#define PLAYER_H

#include "string"
#include "Board.hpp"
using namespace std;

namespace pandemic
{
    class Player
    {
    protected:
    
    public:
        City location;
        Board &gameBoard;
        set<City> cards;
        Player(Board &, City);
        virtual Player &drive(City);
        virtual Player &fly_direct(City);
        virtual Player &fly_charter(City);
        virtual Player &fly_shuttle(City);

        virtual Player &build();
        virtual Player &discover_cure(Color);
        virtual Player &treat(City);

        virtual string role();
        virtual Player &take_card(City);
        void remove_cards();
    };
}
#endif