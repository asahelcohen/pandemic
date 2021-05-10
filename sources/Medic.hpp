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
        std::string role();
    };

}
#endif