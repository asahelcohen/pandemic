#include "OperationsExpert.hpp"
namespace pandemic
{
    OperationsExpert &OperationsExpert::build()
    {
        if (gameBoard.cityResearch.at(location))
        {
            return *this;
        }
        gameBoard.cityResearch.at(location) = true;
        return *this;
    }

    string OperationsExpert::role()
    {
        return "OperationsExpert";
    }
};