#include "Player.hpp"
#include <string>

namespace pandemic
{
    Player::Player(Board &b, City startCity) : gameBoard(b), location(startCity) {}
    City &location(City);
    set<City> cards;

    Player &Player::drive(City c)
    {
        if (c == location)
        {
            throw runtime_error("already at location");
        }

        if (gameBoard.cityMap.at(location).find(c) != gameBoard.cityMap.at(location).end())
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
            location = c;
            cards.erase(c);
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

        if ((gameBoard.cityResearch.at(location) == true) && (gameBoard.cityResearch.at(c) == true))
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
        if (gameBoard.cityResearch.at(location) == true)
        {
            return *this;
        }
        else
        {
            if (cards.find(location) != cards.end())
            {
                gameBoard.cityResearch.at(location) = true;
                cards.erase(location);
            }
            else
            {
                throw runtime_error("you need the card of the city to build a research center");
            }
        }

        return *this;
    }
    Player &Player::discover_cure(Color c)
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
        else{
            throw runtime_error("there is no research center here");
        }
    }

    Player &Player::treat(City c)
    {
        if(gameBoard.cityNum.at(location) == 0){
            throw runtime_error("there is nobody to treat here!");
        }
        Color temp = gameBoard.cityColor.at(location);
        if(gameBoard.DiscoveredCures.at(temp) == true){
            gameBoard.cityNum.at(location) = 0;
        }
        else{
            gameBoard.cityNum.at(location) -= 1;
        }
        return *this;
    }

    string Player::role()
    {
        return "Player";
    }
    Player Player::take_card(City c)
    {
        cards.insert(c);
        return *this;
    }
    void Player::remove_cards()
    {
        cards.clear();
    }
};