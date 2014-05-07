#ifndef FIVECARD_H
#define FIVECARD_H

#include "controller.hpp"

class Fivecard: public Game{
	public:
		Fivecard();
		~Fivecard();
		void start(Fivecard *, Deck *, int, int, int);
		void set_players(int);
		int get_players();
		void set_rounds();
		int get_rounds();
		int get_cards_returned();
		void getCardsBack(int, Player *, Deck *);
		void returnCard(int, Player *, Deck *);
		void printHand(Player);
		void playGame(Fivecard *, vector<Player> *, Deck *, int);
		void checkForPoints(Player *);
		void check3(Player *);
		void checkStraights(Player *);
		void clearGame(Deck *, Deck *, vector<Player> *);
		void checkFull(Player *);
	private:
		int rounds;
};
#endif
