
#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Card.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Game {
private:
	//private members and functions
	int turn;
	int direction;
	int num_of_players;
	int init_num_of_cards;
	bool over;
	//Card current;
	vector<Player> players;

	//Private Copy C'tor and operator= , To ensure that their default implementation is not activated
	Game(const Game& g){};
	Game operator= (const Game& p){};


public:
	//public members and functions
	//C'tor
	Game() :turn(0), direction(1), over(false) {};
	//Functions
	void start();
};
#endif
