#ifndef SCIENTIST_H
#define SCIENTIST_H

// discover_cure(); //  can discover cure by using any n card(the rest need 5)
#include "Player.hpp"

namespace pandemic{
    class Scientist : public Player{
        using Player::Player;
        Player &discover_cure();
    };

}
#endif