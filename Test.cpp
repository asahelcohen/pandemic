#include "doctest.h"

#include "Board.hpp"

#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

#include <iostream>
#include <stdexcept>

using namespace pandemic;
using namespace std;

Board board; // Initialize an empty board (with 0 disease cubes in any city).

TEST_CASE("create a board ")
{
    CHECK(board.is_clean() == true);
    board[City::Kinshasa] = 3;      // put 3 yellow disease cubes in Kinshasa.
    board[City::Kinshasa] = 2;      // change number of disease cubes in Kinshasa to 2.
    board[City::HongKong] = 3;      // put 3 yellow disease cubes in MexicoCity
    board[City::HoChiMinhCity] = 1; // put 1 red disease cube in HoChiMinhCity
    board[City::Chicago] = 1;       // put 1 blue disease cube in Chicago
    board[City::Bogota] = 1;        // put 1 blue disease cube in Bogota
    board[City::Delhi] = 2;         // put 2 black disease cube in Delhi
	board[City::Atlanta] = 2;
	board[City::Miami] = 6;
	board[City::Sydney] = 7;
    CHECK(board.is_clean() == false);
}

TEST_CASE("create players")
{
    OperationsExpert OE{board, City::Atlanta};
    Dispatcher dis{board, City::Sydney};
    FieldDoctor FD{board, City::Khartoum};
    GeneSplicer GS{board, City::Baghdad};
    Medic med{board, City::Cairo};
    Researcher res{board, City::Taipei};
    Virologist vir{board, City::NewYork};
    Scientist sci{board, City::Riyadh, 4};
}

TEST_CASE("OperationsExpert")
{
    OperationsExpert player{board, City::Atlanta};
	player.take_card(City::Atlanta);
	player.build(); //build in atlanta, but dont take card
	player.treat(City::Atlanta);
	CHECK(board[City::Atlanta] == 1);
	CHECK(player.gameBoard.cityResearch.at(City::Atlanta) == true);
}

TEST_CASE("Dispatcher")
{
    Dispatcher player{board, City::HoChiMinhCity};
	player.take_card(City::HoChiMinhCity);
	player.build();
	CHECK_THROWS(player.treat(City::HoChiMinhCity));
    player.fly_direct(City::SanFrancisco);
	CHECK(player.location == City::SanFrancisco);
}

TEST_CASE("FieldDoctor")
{
    FieldDoctor player{board, City::Atlanta};
	player.treat(City::Miami);
	CHECK(board[City::Miami] == 5);
}

TEST_CASE("GeneSplicer")
{
    GeneSplicer player{board, City::Sydney};
	CHECK_THROWS(player.build());
	player.take_card(City::Atlanta);
	player.take_card(City::NewYork);
	player.take_card(City::Bogota);
	player.take_card(City::Algiers);
	player.take_card(City::Jakarta);
	player.take_card(City::Sydney);
	player.build();
	player.treat(City::Sydney);
	CHECK(board[City::Sydney] == 6);
	player.discover_cure(Color::Red);
	player.treat(City::Sydney);
	CHECK(board[City::Sydney] == 0);
}

TEST_CASE("Medic")
{
	board[City::HoChiMinhCity] = 8;
    Medic player{board, City::HoChiMinhCity};
	player.take_card(City::HoChiMinhCity);
	player.build();
	CHECK(board[City::HoChiMinhCity] == 8);
	player.drive(City::Manila);
	player.take_card(City::Manila);
	player.build();
	player.take_card(City::HongKong);
	player.take_card(City::Beijing);
	player.take_card(City::Osaka);
	player.take_card(City::Taipei);
	player.take_card(City::Sydney);
	player.discover_cure(Color::Red);
	player.drive(City::HoChiMinhCity);
	CHECK(board[City::HoChiMinhCity] == 8);
}

TEST_CASE("Researcher")
{
    Researcher player{board, City::Seoul};
	player.take_card(City::HongKong);
	player.take_card(City::Beijing);
	player.take_card(City::Osaka);
	player.take_card(City::Taipei);
	player.take_card(City::Sydney);
	CHECK_NOTHROW(player.discover_cure(Color::Red));
}

TEST_CASE("Virologist")
{
    Virologist player{board, City::Atlanta};
	board[City::HoChiMinhCity] = 8;
	player.take_card(City::HoChiMinhCity);
	player.treat(City::HoChiMinhCity);
	CHECK(board[City::HoChiMinhCity] == 7);
}

TEST_CASE("Scientist")
{
    Scientist player{board, City::SaoPaulo, 3};
	player.take_card(City::SaoPaulo);
	player.build();
	player.take_card(City::Lagos);
	player.take_card(City::Johannesburg);
	player.take_card(City::MexicoCity);
	CHECK_NOTHROW(player.discover_cure(Color::Yellow));	
}
