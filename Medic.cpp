#include "Medic.hpp"

namespace pandemic
{
    Medic &Medic::treat(City c)
    {
        if(gameBoard.cityNum.at(location) == 0){
            throw runtime_error("there is nobody to treat here!");
        }       
        gameBoard.cityNum.at(location) = 0;  
        return *this;
    }

    string Medic::role()
    {
        return "Medic";
    }
};