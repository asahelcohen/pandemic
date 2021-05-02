#include "Player.hpp"
#include <string>

namespace pandemic
{
    Player::Player(Board &d, City startCity) : gameBoard(d), location(startCity){}
    City &location(City);
    // cards

    Player &Player::drive(City)
    {
        return *this;
    }
    Player &Player::fly_direct(City)
    {
        return *this;
    }
    Player &Player::fly_charter(City)
    {
        return *this;
    }
    Player &Player::fly_shuttle(City)
    {
        return *this;
    }

    Player &Player::build()
    {
        return *this;
    }
    Player &Player::discover_cure()
    {
        return *this;
    }
    Player &Player::treat()
    {
        return *this;
    }

    string Player::role()
    {
        return "s";
    }
    Player Player::take_card(City)
    {
        return *this;
    }
};