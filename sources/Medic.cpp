#include "Medic.hpp"

namespace pandemic
{
    Medic &Medic::treat(City c)
    {
        if (gameBoard.cityNum.at(location) == 0)
        {
            throw runtime_error("there is nobody to treat here!");
        }
        gameBoard.cityNum.at(location) = 0;
        return *this;
    }

    Medic &Medic::drive(City c)
    {
        if (c == location)
        {
            throw runtime_error("already at location");
        }

        if (pandemic::Board::cityMap.at(location).find(c) != pandemic::Board::cityMap.at(location).end())
        {
            location = c;
        }
        else
        {
            throw runtime_error("you can only drive to neighbor cities");
        }

        if (gameBoard.cityNum.at(location) != 0)
        {
            if(gameBoard.DiscoveredCures.at(pandemic::Board::cityColor.at(location)))
            {
                gameBoard.cityNum.at(location) = 0;
            }
        }

        return *this;
    }
    Medic &Medic::fly_direct(City c)
    {
        if (c == location)
        {
            throw runtime_error("already at location");
        }

        if (cards.find(c) != cards.end())
        {
            location = c;
            cards.erase(c);
        }
        else
        {
            throw runtime_error("you can only fly if you have a card of the city");
        }

        if (gameBoard.cityNum.at(location) != 0)
        {
            if(gameBoard.DiscoveredCures.at(pandemic::Board::cityColor.at(location)))
            {
                gameBoard.cityNum.at(location) = 0;
            }
        }

        return *this;
    }
    Medic &Medic::fly_charter(City c)
    {
        if (c == location)
        {
            throw runtime_error("already at location");
        }

        if (cards.find(location) != cards.end())
        {
            location = c;
            cards.erase(c);
        }
        else
        {
            throw runtime_error("you can only fly if you have a card of your current location");
        }

        if (gameBoard.cityNum.at(location) != 0)
        {
            if(gameBoard.DiscoveredCures.at(pandemic::Board::cityColor.at(location)))
            {
                gameBoard.cityNum.at(location) = 0;
            }
        }

        return *this;
    }
    Medic &Medic::fly_shuttle(City c)
    {
        if (c == location)
        {
            throw runtime_error("already at location");
        }

        if ((gameBoard.cityResearch.at(location)) && (gameBoard.cityResearch.at(c)))
        {
            location = c;
        }
        else
        {
            throw runtime_error("both cities need to have a research center");
        }

        if (gameBoard.cityNum.at(location) != 0)
        {
            if(gameBoard.DiscoveredCures.at(pandemic::Board::cityColor.at(location)))
            {
                gameBoard.cityNum.at(location) = 0;
            }
        }

        return *this;
    }

    string Medic::role()
    {
        return "Medic";
    }
};