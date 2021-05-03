#include "Medic.hpp"

namespace pandemic
{
    Medic &Medic::treat(City c)
    {
        return *this;
    }

    string Medic::role()
    {
        return "Medic";
    }
};