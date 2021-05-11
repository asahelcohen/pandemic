#include "Scientist.hpp"

namespace pandemic
{
    Scientist::Scientist(Board &b, City c, int n)
        : Player(b, c), n(n)
    {
    }

    Scientist &Scientist::discover_cure(Color c)
    {
        if (!gameBoard.DiscoveredCures.at(c))
        {
            if (gameBoard.cityResearch.at(location))
            {
                if(n == 0){
                    gameBoard.DiscoveredCures.at(c) = true;
                    return *this;
                }
                set<City> tempN;
                int counter = 0;
                std::set<pandemic::City>::iterator it = cards.cbegin();
                while (it != cards.cend())
                {
                    if (pandemic::Board::cityColor.at(*it) == c)
                    {
                        ++counter;
                        tempN.insert(*it);
                        if (counter == n)
                        {
                            gameBoard.DiscoveredCures.at(c) = true;
                            std::set<City>::iterator it1 = tempN.cbegin();
                            while (it1 != tempN.cend())
                            {
                                cards.erase(*it1++);
                                // it1++;
                            }
                            return *this;
                        }
                    }
                    it++;
                }
                cout << n << "ffffffffffffffffff" << endl;
                throw runtime_error("you need n cards of the color to discover cure");
            }
            throw runtime_error("there is no research center here");
        }
        return *this;
    }

    string Scientist::role()
    {
        return "Scientist";
    }
};