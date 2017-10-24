/*
Gavin McGee
gm106214@ohio.edu
CS2401
11/12/16
*/
//Header file for the Othello game class, derived from the Savitch game class

#ifndef OTHELLO_H
#define OTHELLO_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <queue>
#include <string>
#include "game.h"  //All credit for the contents of this file go to Walter Savitch, taken from Data Structures and Other Objects Using C++
#include "space.h"

namespace main_savitch_14{

class Othello
:public game
{
	public:
	Othello();  //Default constructor
	void make_move(const std::string& move);  //Makes a move
	void restart();  //Resets the game
	game* clone() const;  //Makes a copy of the game
	void compute_moves(std::queue<std::string>& moves) const;  //Gives a queue of al legal moves
	void display_status() const;  //Displays the current gameboard to command line
	int evaluate() const;
	bool is_game_over() const;  //Checks if the game has ended
	bool is_legal(const std::string& move) const;  //Checks if a move is legal
	bool north(int r, int c) const;  //Checks north
	bool noreast(int r, int c) const;  //Checks north-east
	bool east(int r, int c) const;  //Checks east
	bool soueast(int r, int c) const;  //Checks south-east
	bool south(int r, int c) const;  //Checks south
	bool souwest(int r, int c) const;  //Checks south-west
	bool west(int r, int c) const;  //Checks west
	bool norwest(int r, int c) const;  //Checks north-west
	
	private:
	Space board[8][8];
	int pass;
};
}

#endif