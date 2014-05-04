#include "gofish.hpp"

using namespace std;

Gofish::Gofish(){
}

Gofish::~Gofish(){
}

int Gofish::get_players(){
	return this->players;
}

void Gofish::set_players(int players){
	this->players = players;
}

void Gofish::start(Gofish * goFish, Deck *deck, int humans, int ai){
	goFish->p.resize(humans+ai);
	for (int i = 0; i<(humans+ai); i++)
		goFish->p.at(i).number = i+1;
	goFish->set_players(humans+ai);
	goFish->deal(&goFish->p, deck, 7);
	goFish->playGame(goFish, &goFish->p, deck);
}

int Gofish::ask(Player *asking, Player *beingAsked, int cardAskedFor){
	int num = 0;
	for (int i = 0; i<beingAsked->hand.size(); i++){
		if (beingAsked->hand.at(i).number == cardAskedFor){
			asking->hand.push_back(beingAsked->hand.at(i));
			beingAsked->hand.erase(beingAsked->hand.begin()+i);
			i--;
			num ++; 
		}
	}   
	cout<<"Player "<<beingAsked->number<<" had "<<num<<" "<<cardAskedFor<<"'s."<<endl<<endl;
	return num;
}


void Gofish::playGame(Gofish *goFish, vector<Player> *p, Deck *deck){
	int pBeingAsked, cardAskedFor, cardsBack;
	while (1){
		int i = 0;
		for(i = 0; i<goFish->players; i++){
			goFish->checkForWin(&p->at(i));
			goFish->printHand(p->at(i));
			cout<<"Player "<<i+1<<", which player would you like to ask for their cards?  ";
			pBeingAsked = goFish->checkPlayerInput(0, i, goFish->players);
			cout<<"Player "<<i+1<<", what number do you want to ask for?  ";
			cardAskedFor = goFish->checkCard(0);
			cardsBack = ask(&p->at(i), &p->at(pBeingAsked-1), cardAskedFor);
			if(cardsBack == 0)
				p->at(i).hand.push_back(deck->getTopCard(&deck->deck));
			goFish->checkForSet(&p->at(i), deck);
			goFish->checkForWin(&p->at(i));
		}
	}
}

int Gofish::checkPlayerInput(int valid, int i, int players){
	int pBeingAsked;
	while(valid == 0){
		cin>>pBeingAsked;
		valid = errorCheck(pBeingAsked);
		if (pBeingAsked<=0 || pBeingAsked>players || pBeingAsked == i+1){
			valid = 0;
			cout<<"\033[1;31mYou didn't enter a valid player!  Please enter a number between 1 and the number of players playing. \033[0m"<<endl;
		}
	}
	return pBeingAsked;
}

int Gofish::checkCard(int valid){
	int cardAskedFor;
	while(valid == 0){
		cin>>cardAskedFor;
		valid = errorCheck(cardAskedFor);
		if (cardAskedFor<1 || cardAskedFor>13){
			valid = 0;
			cout<<"You didn't enter a valid card number!  Please enter a number between 1 and 13. "<<endl;
		}
	}
	return cardAskedFor;
}



void Gofish::checkForSet(Player *p, Deck *ocean){
	int count = 0;
	for (int j = 0; j<=13; j++){
		count = 0;
		for(int i = 0; i<p->hand.size(); i++){
			if (p->hand.at(i).number == j){
				count++;
			}
			if (count == 4){
				for (int k = 0; k<p->hand.size(); k++){
					if (p->hand.at(k).number == j){
						ocean->discard.push_back(p->hand.at(k));
						p->hand.erase(p->hand.begin()+k);
						k--;
						i--;
					}
				}
				cout<<"You got a set of "<<i<<"'s!  Congratulations!"<<endl;
			}
		}
	}
}


void Gofish::checkForWin(Player *p){
	if (p->hand.size() <= 0){
		cout<<"Player "<<p->number<<" wins!!  Congratulations!"<<endl;
		exit(1);
	}
}

