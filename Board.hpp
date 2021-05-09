#ifndef BOARD_H
#define BOARD_H
#include "Color.hpp"
#include "City.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
using namespace std;


namespace pandemic
{
    class Board
    {
    public:
        static map<City, set<City>> cityMap;
        static map<City, Color> cityColor;
        map<City, int> cityNum;
        map<City, bool> cityResearch;
        map<Color, bool> DiscoveredCures;

        Board();

        int &operator[](City city);
        const int operator[](const City city) const;

        friend ostream& operator << (ostream &os, const Board &unit);

        bool is_clean();
        void remove_cures();
        void remove_stations();

        ~Board(){};
    };
}

#endif