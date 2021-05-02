#ifndef DISPATCHER_H
#define DISPATCHER_H
#include "Player.hpp"
//can fly from city with research center to anywhere without using city card

namespace pandemic
{
    class Dispatcher : public Player
    {
        public:
        Player &fly_direct(City);
        Player &fly_charter(City);
        Player &fly_shuttle(City);
        protected:

    };
}
#endif