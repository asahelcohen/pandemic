#ifndef OPERATIONSEXPERT_H
#define OPERATIONSEXPERT_H

// build(); //without throwing card
#include "Player.hpp"

namespace pandemic
{
    class OperationsExpert : public Player
    {
    public:
        using Player::Player;
        OperationsExpert &build();
    };

}
#endif