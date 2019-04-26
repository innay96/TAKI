#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include<vector>
#include<string>

using namespace std;

class Player {
private:
	//private members
	string name;
	int num_of_cards;
	vector<Card> cardsVec;
	sign curr_sign;

public:
	//public members
	Player(){};
	Player(string name, int num_of_cards) :name(name), num_of_cards(num_of_cards), curr_sign(sign::NAS){};
	Player(const Player& p);

	bool play(Card& card);
	void generateCards(const int& num_of_cards);
	Player& operator=(const Player& player);
	string getname() { return name;}
	int getNumOfCards() {return num_of_cards;}
	sign getCurr_sign() const{return curr_sign;}
	void reset_curr_sign() {curr_sign = sign::NAS;}
};
#endif



