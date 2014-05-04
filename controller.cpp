#include "game.hpp"
#include "controller.hpp"
#include "errorcheck.cpp"
#include <vector>
#include <string>

using namespace std;

Controller::Controller(){}

Controller::~Controller(){}

string Controller::get_game(){
	int valid = 1;
	string game;
	cout<<"Welcome to Lucy's Card Game Player!"<<endl;
	cout<<"\033[1;32Would you like to play Go fish or 5-Card draw?\033[0m";
	while (valid == 1){
		cin>>game;
		if (game != "Go Fish" && game !="Go fish" && game != "5-Card Draw" && game != "5-Card draw"){
			cout<<"\033[1;31mYou didn't input a valid string!  Please enter either 'Go Fish' or '5-Card Draw': \033[0m";
			valid = 1;
		}
		else
			valid = 0;
	}
	return game;
}

int Controller::get_humans(){
	int humans, valid = 1;
	cout<<"\033[1;32How many humans will be playing this game?\033[0m";
	while (valid == 1){
		cin>>humans;
		valid = errorCheck(humans);
		if (humans<1 || humans>6){
			cout<<"\033[1;31mYou didn't input a valid number!  Please enter a number between 2 and 6: \033[0m";
			valid = 1;
		}
		else
			valid = 0;
	}
	return humans;
}

int Controller::get_ai(){
	int ai, valid = 1;
	cout<<"\033[1;32How many ai will be playing?\033[0m";
	while (valid == 1){
		cin>>ai;
		valid = errorCheck(ai);
		if (ai<1 || ai>4){
			cout<<"\033[1;31mYou didn't input a valid number!  Please enter a number between 2 and 6: \033[0m";
			valid = 1;
		}
		else 
			valid = 0;
	}
	return ai;
}

void Controller::start(){
	this->game = get_game();
	this->humans = get_humans();
	this->ai = get_ai();
	Deck* deck = new Deck();
	deck->deck.resize(52);
	deck->deck.shuffle(&deck);
	if (this->game == "Go Fish" || this->game == "Go fish"){
		Gofish* goFish = new Gofish();
		goFish->start(&goFish, &deck, this->humans, this->ai);	
	}
	/*else if (game == "5-Card draw" || game == "5-card draw" || game == "5-Card Draw" || game == "5-card Draw"){
		Fivecard* fiveCard;
		fiveCard->start(&fiveCard, &deck, this->humans, this->ai);
	}*/
}


