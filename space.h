/*
Gavin McGee
gm106214@ohio.edu
CS2401
11/12/16
*/
//Contains the space class for the Othello project

#ifndef SPACE_H
#define SPACE_H

#include <iostream>

class Space{  //Class for  single space on the board
	public:
	Space(){space_state = 0;}
	void set_state(int i){space_state = i;}
	const int state() const{return space_state;}
	
	private:
	int space_state;  //0 = empty, 1 = black, 2 = white
};

#endif