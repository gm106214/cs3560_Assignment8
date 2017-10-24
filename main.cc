/*
Gavin McGee
gm106214@ohio.edu
CS2401
11/13/16
*/
//Main program for the Othello Game Project

#include <iostream>
#include "Othello.h"
#include "game.h"
#include "colors.h"
#include "space.h"

using namespace std;

int main(){
	bool r;
	char c;
	int win;
	int human = 0;  //Number of human wins
	int computer = 0;  //Number of computer wins
	int ties = 0;  //Number of ties
	main_savitch_14::Othello g;
	do{
		cout << "Welcome to Othello. Please enter all moves in the format \"columnrow\" (ex. A1).\nIf there are no valid moves you can make, enter \"Pass\".\n";
		win = g.play();
		if(win == 0){
			cout << "Congradulations! You win!\n";
			++human;
		}
		else if(win == 1){
			cout << "Game tied.\n";
			++ties;
		}
		else{
			cout << "Sorry, you lose.\n";
			++computer;
		}
		cout << "Would you like to play again? (y/n): ";
		cin >> c;
		if(c == 'y' || c == 'Y'){
			r = true;
		}
		else{
			r = false;
		}
	}while(r);
	cout << "Session results:\n";
	cout << "Wins: " << human << endl;
	cout << "Losses: " << computer << endl;
	cout << "Ties: "  << ties << endl;
	cout << "Thanks for playing!\n";
	return 0;
}