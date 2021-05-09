#include "Dispatcher.hpp"

namespace pandemic
{
    Dispatcher &Dispatcher::fly_direct(City c)
    {
        if (c == location)
        {
            throw runtime_error("already at location");
        }
        location = c;

        return *this;
    }

    string Dispatcher::role()
    {
        return "Dispatcher";
    }
};