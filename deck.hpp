#ifndef DECK_H
#define DECK_H

#include "controller.hpp"
#include<vector>
#include<string>

using namespace std;

struct Card{
	int number;
	string suit;
};

class Deck{
	public:
		Deck();
		~Deck();
		Deck(int);
		void shuffle(vector<Card>*);
		Card getTopCard(vector<Card>*);
		vector<Card> const &get_deck();
		vector<Card> const &get_discard();
		void set_deck(vector<Card>);
		void set_discard(vector<Card>);
		int get_cards_in_play();
		void set_cards_in_play();
	private:
		int cards_in_play;
		vector<Card> deck;
		vector<Card> discard;
	friend class Controller;
};
#endif
