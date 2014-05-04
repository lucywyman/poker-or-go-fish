#ifndef GAME_H
#define GAME_H

#include<vector>
#include "player.hpp"
#include "deck.hpp"

using namespace std;

class Game{
	public:
		Game();
		~Game(); 
		virtual void deal(vector<Player>*, Deck*, int);
		void printHand(Player);
		virtual int get_humans();
		virtual void set_humans(int);
		virtual int get_ai();
		virtual void set_ai(int);
		char get_win();
		void set_win();
		vector<Card> const &get_P();
		void set_P(vector<Player>);
		int players;
		char win;
		vector<Player> P;
		int errorCheck(int);
};
#endif
