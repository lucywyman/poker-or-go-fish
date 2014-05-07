#ifndef PLAYER_H
#define PLAYER_H

#include "deck.hpp"
#include<vector>
#include<string>

using namespace std;

class Player{
	public:
		Player();
		~Player();
		vector<Card> const &get_hand();
		void set_hand(vector<Card>);
		int get_number();
		void set_number(int);
		vector<Card> hand;
		int number;
		int points;
};

#endif
