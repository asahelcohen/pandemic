#include "OperationsExpert.hpp"
namespace pandemic
{
    OperationsExpert &OperationsExpert::build()
    {
        if (gameBoard.cityResearch.at(location) == true)
        {
            return *this;
        }
        else
        {
            gameBoard.cityResearch.at(location) = true;
        }

        return *this;
    }

    string OperationsExpert::role()
    {
        return "OperationsExpert";
    }
};