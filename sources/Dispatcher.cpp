#include "Dispatcher.hpp"

namespace pandemic
{
    Dispatcher &Dispatcher::fly_direct(City c)
    {
        if (c == location)
        {
            throw runtime_error("already at location");
        }
        if (gameBoard.cityResearch.at(location))
        {
            location = c;
            return *this;
        }
        if (cards.find(c) != cards.end())
        {
            cards.erase(c);
            location = c;
            return *this;
        }
        throw runtime_error("you need a research center in order to fly");
    }

    string Dispatcher::role()
    {
        return "Dispatcher";
    }
};