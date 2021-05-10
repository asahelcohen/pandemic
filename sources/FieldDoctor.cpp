#include "FieldDoctor.hpp"

namespace pandemic
{
    FieldDoctor &FieldDoctor::treat(City c)
    {
        if (gameBoard.cityNum.at(c) == 0)
        {
            throw runtime_error("there is nobody to treat here!");
        }
        if (pandemic::Board::cityMap.at(location).find(c) != pandemic::Board::cityMap.at(location).end())
        {
            Color temp = pandemic::Board::cityColor.at(location);
            if (gameBoard.DiscoveredCures.at(temp))
            {
                gameBoard.cityNum.at(c) = 0;
            }
            else
            {
                gameBoard.cityNum.at(c) -= 1;
            }
        }
        else
        {
            throw runtime_error("you can only treat as a FieldDoctor neighbor cities");
        }

        return *this;
    }

    string FieldDoctor::role()
    {
        return "FieldDoctor";
    }
};