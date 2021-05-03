#ifndef GENEPLICER_H
#define GENESPLICER_H

// discover_cure(); // can discover_cure by using any five card, they dont have to be the same colour of the disease
#include "Player.hpp"

namespace pandemic
{
    class GeneSplicer : public Player
    {
    public:
        using Player::Player;
        GeneSplicer &discover_cure(Color);
    };

}
#endif