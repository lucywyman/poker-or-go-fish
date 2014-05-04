#ifndef GOFISH_H
#define GOFISH_H

#include "game.hpp"
#include "deck.hpp"
#include "player.hpp"

using namespace std;

class Gofish: public Game{
	public:
		Gofish();
		~Gofish();
		void start(Gofish *, Deck *, int, int);
		int ask(Player *, Player *, int);
		void playGame(Gofish *, vector<Player> *, Deck *);
		int checkPlayerInput(int, int, int);
		int checkCard(int);
		void checkForSet(Player *, Deck *);
		void checkForWin(Player *);
};
#endif
