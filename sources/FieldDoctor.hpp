#ifndef FIELDDOCTOR_H
#define FIELDDOCTOR_H

// treat(); //can treat any city connected to him without using city card
#include "Player.hpp"

namespace pandemic
{
    class FieldDoctor : public Player
    {
    public:
        using Player::Player;
        FieldDoctor &treat(City);
        std::string role();
    };

}
#endif