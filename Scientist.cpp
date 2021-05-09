#include "Scientist.hpp"

namespace pandemic
{
    Scientist::Scientist(Board b, City c, unsigned int n)
        : Player(b, c), n(n)
    {
    }

    Scientist &Scientist::discover_cure(Color c)
    {
        if (gameBoard.cityResearch.at(location) == true)
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
                        if (counter == n)
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
            throw runtime_error("you need more cards of the color to discover cure");
        }
        else{
            throw runtime_error("there is no research center here");
        }
    }

    string Scientist::role()
    {
        return "Scientist";
    }
};