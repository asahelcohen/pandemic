#include "Researcher.hpp"

namespace pandemic
{
    Researcher &Researcher::discover_cure(Color c)
    {
        return *this;
    }

    string Researcher::role()
    {
        return "Researcher";
    }
};