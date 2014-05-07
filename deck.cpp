#include "deck.hpp"
#include <iostream>

using namespace std;

Deck::Deck(){
	this->cards_in_play = 52;
}

Deck::~Deck(){
	cout<<"DELETING"<<endl;
}

Deck::Deck(int size){
	this->cards_in_play = size;
	string suitstring;
	this->deck.resize(size);
	int i = 0;
	for (int suit = 1; suit<=4; suit++){
		if (suit == 1)
			suitstring = "hearts";
		else if (suit == 2)
			suitstring = "spades";
		else if (suit == 3)
			suitstring = "diamonds";
		else 
			suitstring = "clubs";
		for (int card = 1; card<=(size/4); card++){
			this->deck.at(i).suit = suitstring;
			this->deck.at(i).number = card;
			i++;
		}
	}  
}

/*vector<Card> Deck::&get_deck(){
	return this->deck;
}

void Deck::set_deck(vector<Card> deck){
	this->deck = deck;
}

vector<Card> Deck::&get_discard(){
	return this->discard;
}

void Deck::set_discard(vector<Card> discard){
	this->discard = discard;
}

int Deck::get_cards_in_play(){
	return this->cards_in_play;
}

void Deck::set_cards_in_play(int cards_in_play){
	this->cards_in_play;
}
*/
void Deck::shuffle(vector<Card> *deck){
	int i, j, a;
	Card temp;
	srand(time(NULL));
	a = deck->size()-1;
	for(int b = 0; b<4; b++){
		for(i = 0; i<a/4; i++){
			j = rand()%a;
			temp = deck->at(i);
			deck->at(i) = deck->at(j);
			deck->at(j) = temp;
		}
	}
}

Card Deck::getTopCard(vector<Card> *deck){
	Card a = deck->at(0);
	deck->erase(deck->begin());
	if (deck->size() == 0){
		cout<<"You're out of cards!  Game over!"<<endl;
		exit(1);
	}
	return a;
}


