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

        Board()
        {
            cityNum = {{City::Algiers, 0}, {City::Atlanta, 0}, {City::Baghdad, 0}, {City::Bangkok, 0}, {City::Beijing, 0}, {City::Bogota, 0}, {City::BuenosAires, 0}, {City::Cairo, 0}, {City::Chennai, 0}, {City::Chicago, 0}, {City::Delhi, 0}, {City::Essen, 0}, {City::HoChiMinhCity, 0}, {City::HongKong, 0}, {City::Istanbul, 0}, {City::Jakarta, 0}, {City::Johannesburg, 0}, {City::Karachi, 0}, {City::Khartoum, 0}, {City::Kinshasa, 0}, {City::Kolkata, 0}, {City::Lagos, 0}, {City::Lima, 0}, {City::London, 0}, {City::LosAngeles, 0}, {City::Madrid, 0}, {City::Manila, 0}, {City::MexicoCity, 0}, {City::Miami, 0}, {City::Milan, 0}, {City::Montreal, 0}, {City::Moscow, 0}, {City::Mumbai, 0}, {City::NewYork, 0}, {City::Osaka, 0}, {City::Paris, 0}, {City::Riyadh, 0}, {City::SanFrancisco, 0}, {City::Santiago, 0}, {City::SaoPaulo, 0}, {City::Seoul, 0}, {City::Shanghai, 0}, {City::StPetersburg, 0}, {City::Sydney, 0}, {City::Taipei, 0}, {City::Tehran, 0}, {City::Tokyo, 0}, {City::Washington, 0}};
            DiscoveredCures = {{Color::Black, false},
                               {Color::Blue, false},
                               {Color::Red, false},
                               {Color::Yellow, false}};
            cityResearch = {{City::Algiers, false}, {City::Atlanta, false}, {City::Baghdad, false}, {City::Bangkok, false}, {City::Beijing, false}, {City::Bogota, false}, {City::BuenosAires, false}, {City::Cairo, false}, {City::Chennai, false}, {City::Chicago, false}, {City::Delhi, false}, {City::Essen, false}, {City::HoChiMinhCity, false}, {City::HongKong, false}, {City::Istanbul, false}, {City::Jakarta, false}, {City::Johannesburg, false}, {City::Karachi, false}, {City::Khartoum, false}, {City::Kinshasa, false}, {City::Kolkata, false}, {City::Lagos, false}, {City::Lima, false}, {City::London, false}, {City::LosAngeles, false}, {City::Madrid, false}, {City::Manila, false}, {City::MexicoCity, false}, {City::Miami, false}, {City::Milan, false}, {City::Montreal, false}, {City::Moscow, false}, {City::Mumbai, false}, {City::NewYork, false}, {City::Osaka, false}, {City::Paris, false}, {City::Riyadh, false}, {City::SanFrancisco, false}, {City::Santiago, false}, {City::SaoPaulo, false}, {City::Seoul, false}, {City::Shanghai, false}, {City::StPetersburg, false}, {City::Sydney, false}, {City::Taipei, false}, {City::Tehran, false}, {City::Tokyo, false}, {City::Washington, false}};
        };

        int &operator[](City city);
        int operator[](const City city) const;
        friend std::ostream &operator<<(std::ostream &os, const Board &b);
        //friend std::ostream& operator << (ostream os, const Board &b);
        bool is_clean();
        void remove_cures();
        void remove_stations();

        ~Board(){};
    };
}

#endif