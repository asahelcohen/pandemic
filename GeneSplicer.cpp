#include "GeneSplicer.hpp"

namespace pandemic
{
    GeneSplicer &GeneSplicer::discover_cure(Color c)
    {
        if (gameBoard.cityResearch.at(location) == true)
        {
            if(cards.size() >= 5){
                std::set<City>::iterator it;
                it = cards.begin();
                for(int i=0; i < 5; i++)
                {
                    cards.erase(it);
                    ++it;
                }
            }
            else{
                throw runtime_error("you need five cards to discover cure");
            }
        }
        else{
            throw runtime_error("there is no research center here");
        }
        return *this;
    }

    string GeneSplicer::role()
    {
        return "GeneSplicer";
    }
};