#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "deck.hpp"
#include "game.hpp"
#include "player.hpp"
#include "gofish.hpp"
#include "errorcheck.hpp"
#include <iostream>
#include <string>

using namespace std;

class Controller {
	public:
		Controller();
		~Controller();
		void start();
		string get_game();
		void set_game(string);
		int get_humans();
		void set_humans(int);
		int get_ai();
		void set_ai(int);
		string game;
		int ai;
		int humans;	
};

#endif
