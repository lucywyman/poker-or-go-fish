#include "game.hpp"
#include<iostream>

using namespace std;

Game::Game(){
}

Game::~Game(){
}

/*int Game::get_humans(){
	return this->players;
}

void Game::set_humans(int players){
	this->players = players;
}

char Game::get_win(){
	return this->win;
}

void Game::set_win(char win){
	this->win = win;
}

vector<Player> Game::const &get_P(){
	return this->P;
}

void Game::set_P(vector<Player> P){
	this->P = P;
}
*/

int Game::get_players(){
	return this->players;
}

void Game::set_players(int players){
	this->players = players;
}

void Game::deal(vector<Player> *P, Deck *deck, int size){
	Card a;
	for (int i = 0; i<P->size(); i++){
		for (int j = 0; j<size; j++){
			a = deck->getTopCard(&deck->deck);
			P->at(i).hand.push_back(a);
		}
	}
}

void Game::printHand(Player p){
	cout<<endl;
	cout<<"\033[1;34mPlayer "<<p.number<<", here's your hand:\33[0m"<<endl;
	for (int i = 0; i<p.hand.size();i++)
		cout<<"\033[1;35m"<<p.hand.at(i).number<<" of "<<p.hand.at(i).suit<<"\033[0m"<<endl;
	cout<<endl;
}


