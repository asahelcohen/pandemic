#include "Virologist.hpp"

namespace pandemic
{
    Virologist &Virologist::treat(City c)
    {
        if (gameBoard.cityNum.at(c) == 0)
        {
            throw runtime_error("there is nobody to treat there!");
        }
        if (cards.find(c) != cards.end())
        {
            if (gameBoard.DiscoveredCures.at(pandemic::Board::cityColor.at(c)))
            {
                gameBoard.cityNum.at(c) = 0;
            }
            else
            {
                gameBoard.cityNum.at(c) -= 1;
            }
            cards.erase(c);
        }
        else{
            throw runtime_error("you need city card to treat");
        }

        return *this;
    }

    string Virologist::role()
    {
        return "Virologist";
    }
};