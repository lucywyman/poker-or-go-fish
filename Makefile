CPPC=clang++

all: main.o controller.o deck.o player.o game.o goFish.o
	$(CPPC) main.o controller.o deck.o player.o game.o goFish.o -o game

controller.o: controller.cpp
	$(CPPC) -c controller.cpp 

deck.o: deck.cpp
	$(CPPC) -c deck.cpp

player.o: player.cpp
	$(CPPC) -c player.cpp

game.o: game.cpp
	$(CPPC) -c game.cpp

goFish.o: goFish.cpp
	$(CPPC) -c goFish.cpp

clean:
	rm -rf *.o game
