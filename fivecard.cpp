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

void Fivecard::set_rounds(){
	int round;
	cout<<"How many rounds would you like to play?  ";
	cin>>round;
	this->rounds = round;
}

int Fivecard::get_rounds(){
	return this->rounds;
}

void Fivecard::printHand(Player p){
	cout<<endl;
	cout<<"\033[1;34mPlayer "<<p.number<<", here's your hand:\33[0m"<<endl;
	for (int i = 0; i<p.hand.size();i++)
		cout<<i+1<<"\033[1;35m  "<<p.hand.at(i).number<<" of "<<p.hand.at(i).suit<<"\033[0m"<<endl;
	cout<<endl;
}


void Fivecard::start(Fivecard *fiveCard, Deck *deck, int humans, int ai, int rounds){
	fiveCard->p.resize(humans+ai);
	for (int i = 0; i<humans+ai; i++)
		fiveCard->p.at(i).number = i+1;
	fiveCard->set_players(humans+ai);
	fiveCard->deal(&fiveCard->p, deck, 5);
	fiveCard->playGame(fiveCard, &fiveCard->p, deck, rounds);
}

int Fivecard::get_cards_returned(){
	int valid = 1, cards;
	cout<<"How many cards do you want to return?  ";
	while (valid == 1){
		cin>>cards;
		valid = errorCheck(cards);
		if (cards <0 || cards>4){
			cout<<"\033[1;31mYou didn't enter a valid number!  Please enter a number between 0 and 4.  \033[0m"<<endl;
			valid = 1;
		}
		else
			valid = 0;
	}
	return cards;
}

void Fivecard::returnCard(int cards, Player *player, Deck *discard){
	int beingReturned, valid = 1;
	for (int i = 0; i<cards; i++){
		printHand(*player);
		valid = 1;
		cout<<"Which card would you like to return? Please enter as an integer!  ";
		while (valid == 1){
			cin>>beingReturned;
			valid = errorCheck(cards);
			if (beingReturned>player->hand.size() || beingReturned<1){
				cout<<"\033[1;31mYou didn't enter a valid number!  Please enter a number between 0 and 5.  \033[0m"<<endl;
				valid = 1;
			}
			else
				valid = 0;
		}
		discard->deck.push_back(player->hand.at(beingReturned-1));
		player->hand.erase(player->hand.begin()+beingReturned-1);
	}
}

void Fivecard::getCardsBack(int cards, Player *player, Deck *deck){
	for (int i = 0; i<cards; i++)
		player->hand.push_back(deck->getTopCard(&deck->deck));
}

void Fivecard::playGame(Fivecard *fivecard, vector<Player> *p, Deck *deck, int rounds){
	Deck *discard = new Deck();
	int best = 0;
	for(int i = 0; i<p->size(); i++){
		printHand(p->at(i));
		int cards = fivecard->get_cards_returned();
		fivecard->returnCard(cards, &p->at(i), discard);
		fivecard->getCardsBack(cards, &p->at(i), deck);
		printHand(p->at(i));
		//Would you like to place a bet?
		fivecard->checkForPoints(&p->at(i));			
	}
	cout<<"\033[1;34mPoint totals:  \033[0m"<<endl;
	for (int i= 0; i<p->size(); i++)
		cout<<"\033[1;35mPlayer "<<p->at(i).number<<" has "<<p->at(i).points<<" points"<<endl;
	clearGame(deck, discard, p);
	if (rounds == 1){
		for (int i = 0; i<p->size(); i++){
			if (p->at(i).points > best)
				best = p->at(i).number;
		}
	}
	cout<<"Player "<<best<<" wins!!"<<endl;
	exit(1);
}


void Fivecard::checkForPoints(Player *player){
	check3(player);
	checkStraights(player);
}

void Fivecard::check3(Player *player){
	for (int j = 0; j<13; j++){
		int count = 0;
		for (int i = 0; i<player->hand.size(); i++){
			if (player->hand.at(i).number == j)
				count++;
		}
		if (count == 3){
			cout<<"Congratulations!  You got a 3 of a kind!"<<endl;
			player->points += 10;
		}
		else if (count ==4){
			cout<<"Congratulations!  You got a 4 of a kind!"<<endl;
			player->points += 30;
		}
	}
}

void Fivecard::checkStraights(Player *player){
	int a = player->hand.at(0).number, flush=0, straight=0, count = 0;
	string suit = player->hand.at(0).suit;
	for (int i = 0; i<player->hand.size(); i++){
		count = 0;
		if (player->hand.at(i).suit == suit)
			count++;
	}
	if (count == 5)
		flush++;
	for (int i = 0; i<player->hand.size(); i++){
		if (player->hand.at(i).number<a)
			a = player->hand.at(i).number;
	}
	count = 0;
	for (int j = 0; j<4; j++){
		for (int i = 0; i<player->hand.size(); i++){
			if (player->hand.at(i).number == a+1){
				count++;
				a = a+1;
				break;
			}
		}
		if (count == 5)
			straight++;
	}
	if (straight == 1 && flush == 1){
		cout<<"Congratulations!  You got a straight flush!"<<endl;
		player->points += 50;
	}
	else if (straight == 1 && flush == 0){
		cout<<"Congratulations! You got a straight!"<<endl;
		player->points += 15;
	}
	else if (straight == 0 && flush == 1){
		cout<<"Congratulations! You got a flush!"<<endl;
		player->points += 20;
	}
}

void Fivecard::checkFull(Player *player){
	int count = 0, big = 0, little = 0;
	for (int j = 0; j<13; j++){
		for (int i = 0; i<5; i++){
			if (player->hand.at(i).number==j)
				count++;
		}
		if (count == 3)
			big = 1;
		else if (count == 2)
			little += 1;
	}
	if (big == 1 && little == 1){
		cout<<"Congratulations!  You got a full house!"<<endl;
		player->points += 25;
	}
	else if (little == 2){
		cout<<"Congratulations!  You got two pair!"<<endl;
		player->points += 10;
	}
}

void Fivecard::clearGame(Deck *deck, Deck *discard, vector<Player> *p){
	deck->~Deck();
	discard->~Deck();
	for (int i = 0; i<p->size(); i++){
		for (int j = 0; j<5; j++)
			p->at(i).hand.erase(p->at(i).hand.begin());
	}
}





