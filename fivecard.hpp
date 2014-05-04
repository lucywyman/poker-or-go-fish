#ifndef FIVECARD_H
#define FIVECARD_H

#include "controller.hpp"

using namespace std;

class Fivecard: public Game{
	public:
		Fivecard();
		~Fivecard();
		void start(Fivecard *, Deck *, int, int);
		void set_players(int);
		int get_players();
};
#endif
