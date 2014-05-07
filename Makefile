CPPC=clang++

all: main.o controller.o deck.o player.o game.o goFish.o fivecard.o
	clang++ main.o controller.o deck.o player.o game.o goFish.o fivecard.o -o game

controller.o: controller.cpp
	clang++ -c controller.cpp 

deck.o: deck.cpp
	clang++ -c deck.cpp

player.o: player.cpp
	clang++ -c player.cpp

game.o: game.cpp
	clang++ -c game.cpp

goFish.o: goFish.cpp
	clang++ -c goFish.cpp

fivecard.o: fivecard.cpp
	clang++ -c fivecard.cpp

clean:
	rm -rf *.o game
