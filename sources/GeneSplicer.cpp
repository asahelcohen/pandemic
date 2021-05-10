#include "GeneSplicer.hpp"

namespace pandemic
{
    GeneSplicer &GeneSplicer::discover_cure(Color c)
    {
        if (!gameBoard.DiscoveredCures.at(c))
        {
            if (gameBoard.cityResearch.at(location))
            {
                const int five = 5;
                if (cards.size() >= five)
                {
                    gameBoard.DiscoveredCures.at(c) = true;
                    set<City> temp;
                    std::set<City>::iterator it;
                    it = cards.begin();
                    for (int i = 0; i < five; i++)
                    {
                        temp.insert(*it++);
                    }
                    std::set<City>::iterator it1;
                    it1 = temp.begin();
                    for (int i = 0; i < five; i++)
                    {
                        cards.erase(*it++);
                    }
                }
                else
                {
                    throw runtime_error("you need five cards to discover cure");
                }
            }
            else
            {
                throw runtime_error("there is no research center here");
            }
        }
        return *this;
    }

    string GeneSplicer::role()
    {
        return "GeneSplicer";
    }
};