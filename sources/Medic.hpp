#ifndef MEDIC_H
#define MEDIC_H

// treat(); //when using treat removes all cubes of desease and not only one
#include "Player.hpp"

namespace pandemic
{
    class Medic : public Player
    {
    public:
        using Player::Player;
        Medic &treat(City);
        Medic &drive(City);
        Medic &fly_direct(City);
        Medic &fly_charter(City);
        Medic &fly_shuttle(City);
        std::string role();
    };

}
#endif