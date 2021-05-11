#include "Researcher.hpp"

namespace pandemic
{
    Researcher &Researcher::discover_cure(Color c)
    {
        if (!gameBoard.DiscoveredCures.at(c))
        {
            const int five = 5;
            set<City> tempfive;
            int counter = 0;
            std::set<pandemic::City>::iterator it = cards.begin();
            while (it != cards.end())
            {
                if (pandemic::Board::cityColor.at(*it) == c)
                {
                    counter++;
                    tempfive.insert(*it);
                    if (counter == five)
                    {
                        gameBoard.DiscoveredCures.at(c) = true;
                        std::set<City>::iterator it1 = tempfive.begin();
                        while (it1 != tempfive.end())
                        {
                            cards.erase(*it1++);
                            // it1++;
                        }
                        return *this;
                    }
                }
                it++;
            }
            throw runtime_error("you need five cards of the color to discover cure");
        }
        return *this;
    }

    string Researcher::role()
    {
        return "Researcher";
    }
};