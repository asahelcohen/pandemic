#ifndef DISPATCHER_H
#define DISPATCHER_H
#include "Player.hpp"
//can fly from city with research center to anywhere without using city card

namespace pandemic
{
    class Dispatcher : public Player
    {
    public:
        using Player::Player;
        Dispatcher &fly_direct(City);
        std::string role();
    };
}
#endif