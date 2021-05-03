#ifndef RESEARCHER_H
#define RESEARCHER_H

// discover_cure(); //  can discover cure in any city (doesnt need reaserch lab)
#include "Player.hpp"

namespace pandemic
{
    class Researcher : public Player
    {
    public:
        using Player::Player;
        Researcher &discover_cure(Color);
    };

}
#endif