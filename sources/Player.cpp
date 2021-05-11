#include "Player.hpp"
#include <string>

namespace pandemic
{
    Player::Player(Board &b, City startCity) : gameBoard(b), location(startCity) {}
    City &location(City);
    set<City> cards;
    Board &gameBoard(Board);

    Player &Player::drive(City c)
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

        return *this;
    }
    Player &Player::fly_direct(City c)
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

        return *this;
    }
    Player &Player::fly_charter(City c)
    {
        if (c == location)
        {
            throw runtime_error("already at location");
        }

        if (cards.find(location) != cards.end())
        {
            cards.erase(location);
            location = c;

        }
        else
        {
            throw runtime_error("you can only fly if you have a card of your current location");
        }

        return *this;
    }
    Player &Player::fly_shuttle(City c)
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
        return *this;
    }

    Player &Player::build()
    {
        if (gameBoard.cityResearch.at(location))
        {
            return *this;
        }

        if (cards.find(location) != cards.end())
        {
            gameBoard.cityResearch.at(location) = true;
            cards.erase(location);
        }
        else
        {
            throw runtime_error("you need the card of the city to build a research center");
        }

        return *this;
    }
    Player &Player::discover_cure(Color c)
    {
        if (!gameBoard.DiscoveredCures.at(c))
        {
            if (gameBoard.cityResearch.at(location))
            {
                int five = 5;
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
            throw runtime_error("there is no research center here");
        }
        return *this;
    }

    Player &Player::treat(City c)
    {
        if (gameBoard.cityNum.at(location) == 0)
        {
            throw runtime_error("there is nobody to treat here!");
        }
        Color temp = pandemic::Board::cityColor.at(location);
        if (gameBoard.DiscoveredCures.at(temp))
        {
            gameBoard.cityNum.at(location) = 0;
        }
        else
        {
            gameBoard.cityNum.at(location) -= 1;
        }
        return *this;
    }

    string Player::role()
    {
        return "Player";
    }
    Player &Player::take_card(City c)
    {
        cards.insert(c);
        return *this;
    }
    void Player::remove_cards()
    {
        cards.clear();
    }
};