#ifndef PLAYER_H
#define PLAYER_H

#include "deck.hpp"
#include<vector>

using namespace std;

class Player{
	public:
		Player();
		~Player();
		//Card discard();
		//Card getCard(Deck);
		vector<Card> const &get_hand();
		void set_hand(vector<Card>);
		int get_number();
		void set_number(int);
	private:
		vector<Card> hand;
		int number;
};

#endif
