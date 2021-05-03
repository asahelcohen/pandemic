#include "FieldDoctor.hpp"
namespace pandemic
{
    FieldDoctor &FieldDoctor::treat(City c)
    {
        return *this;
    }

    string FieldDoctor::role()
    {
        return "FieldDoctor";
    }
};