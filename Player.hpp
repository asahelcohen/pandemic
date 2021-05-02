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
        City location;
        Board gameBoard;
        set<City> cards;

    public:
        Player(Board &, City);
        Player &drive(City);
        Player &fly_direct(City);
        Player &fly_charter(City);
        Player &fly_shuttle(City);

        Player &build();
        Player &discover_cure(Color);
        Player &treat(City);

        string role();
        Player take_card(City);
    };
}
#endif