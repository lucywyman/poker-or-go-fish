#include "fivecard.hpp"

using namespace std;

Fivecard::Fivecard(){
}

Fivecard::~Fivecard(){
}

void Fivecard::set_players(int players){
	this->players = players;
}

int Fivecard::get_players(){
	return this->players;
}

void Fivecard::start(Fivecard *fiveCard, Deck *deck, int humans, int ai){
	fiveCard->p.resize(humans+ai);
	for (int i = 0; i<humans+ai; i++)
		fiveCard->p.at(i).number = i+1;
	fiveCard->set_player(humans+ai);
	fiveCard->deal(&fiveCard->p, &deck, 5);
	fiveCard->playeGame(&fiveCard, &fiveCard->p, &deck);
}


