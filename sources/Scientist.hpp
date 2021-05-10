#ifndef SCIENTIST_H
#define SCIENTIST_H

// discover_cure(); //  can discover cure by using any n card(the rest need 5)
#include "Player.hpp"

namespace pandemic
{
    class Scientist : public Player
    {
        int n;
    public:
        //using Player::Player;
        Scientist(Board&, City, int);
        Scientist &discover_cure(Color);
        std::string role();
    };

}
#endif