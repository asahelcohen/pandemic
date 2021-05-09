#include "Researcher.hpp"

namespace pandemic
{
    Researcher &Researcher::discover_cure(Color c)
    {

        set<City> temp;
        int counter = 0;
        std::map<City, Color>::iterator it;
        it = gameBoard.cityColor.begin();
        while (it != gameBoard.cityColor.end())
        {
            if ((it->second) == c)
            {
                if (cards.find(it->first) != cards.end())
                {
                    counter++;
                    temp.insert(it->first);
                    if (counter == 5)
                    {
                        gameBoard.cityResearch.at(location) = true;
                        std::set<City>::iterator it1;
                        it1 = temp.begin();
                        while (it1 != temp.end())
                        {
                            cards.erase(it1);
                        }
                        return *this;
                    }
                }
            }
        }
        throw runtime_error("you need five cards of the color to discover cure");
    }

    string Researcher::role()
    {
        return "Researcher";
    }
};