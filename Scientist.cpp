#include "Scientist.hpp"

namespace pandemic
{
    Scientist::Scientist(Board b, City c, unsigned int n)
        : Player(b, c), n(n)
    {
    }

    Scientist &Scientist::discover_cure(Color c)
    {
        return *this;
    }
};