Othello : main.cc Othello.o game.o
	g++ -Wall main.cc Othello.o game.o -o Othello
Othello.o : game.o Othello.cc
	g++ -Wall -c game.o Othello.cc
game.o : game.cc
	g++ -Wall -c game.cc
clean:
	rm -f *.o *.out Othello *~
