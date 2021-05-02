#ifndef VIROLOGIST_H
#define VIROLOGIST_H

// treat(); //can treat any place in the world without beeing there, by throwing a card of the city
#include "Player.hpp"

namespace pandemic{
    class Virologist : public Player{
        Player &treat();
    };

}
#endif