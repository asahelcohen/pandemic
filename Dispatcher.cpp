#include "Dispatcher.hpp"

namespace pandemic
{
    Dispatcher &Dispatcher::fly_direct(City c)
    {
        return *this;
    }

    string Dispatcher::role()
    {
        return "Dispatcher";
    }
};