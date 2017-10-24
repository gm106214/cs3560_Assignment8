/*
Gavin McGee
gm106214@ohio.edu
CS2401
11/12/16
*/
//Header file for the Othello game class, derived from the Savitch game class

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <string>
#include "Othello.h"
#include "game.h"  //All credit for the contents of this file go to Walter Savitch, taken from Data Structures and Other Objects Using C++
#include "colors.h"  //All credit for the contents of this file go to Matthew Beldyk, mb245002@ohiou.edu
#include "space.h"

using namespace std;

namespace main_savitch_14{

Othello::Othello(){  //Default constructor
	board[3][3].set_state(2);
	board[3][4].set_state(1);
	board[4][3].set_state(1);
	board[4][4].set_state(2);
	pass = 0;
}

void Othello::make_move(const std::string& move){  //Makes a move
	int i = 0;
	int j = 0;
	int p = 1;
	int r = 0;
	int c = 0;
	if(move == "Pass"){
		game::make_move(move);
		++pass;
		return;
	}
	if(moves_completed()%2 != 0){
		p = 2;
	}
	i = toupper(move[0])-'A';
	j = (move[1]-'1');
	board[j][i].set_state(p);
	if(north(j, i)){
		r = j-1;
		c = i;
		while(board[r][c].state() != p){
			board[r][c].set_state(p);
			--r;
		}
	}
	if(noreast(j, i)){
		r = j-1;
		c = i+1;
		while(board[r][c].state() != p){
			board[r][c].set_state(p);
			--r;
			++c;
		}
	}
	if(east(j, i)){
		r = j;
		c = i+1;
		while(board[r][c].state() != p){
			board[r][c].set_state(p);
			++c;
		}
	}
	if(soueast(j, i)){
		r = j+1;
		c = i+1;
		while(board[r][c].state() != p){
			board[r][c].set_state(p);
			++r;
			++c;
		}
	}
	if(south(j, i)){
		r = j+1;
		c = i;
		while(board[r][c].state() != p){
			board[r][c].set_state(p);
			++r;
		}
	}
	if(souwest(j, i)){
		r = j+1;
		c = i-1;
		while(board[r][c].state() != p){
			board[r][c].set_state(p);
			++r;
			--c;
		}
	}
	if(west(j, i)){
		r = j;
		c = i-1;
		while(board[r][c].state() != p){
			board[r][c].set_state(p);
			--c;
		}
	}
	if(norwest(j, i)){
		r = j-1;
		c = i-1;
		while(board[r][c].state() != p){
			board[r][c].set_state(p);
			--r;
			--c;
		}
	}
	if(pass > 0){
		--pass;
	}
	game::make_move(move);
}

void Othello::restart(){  //Resets the game
	for(int i = 0; i < 8; i++){
		for(int j = 0; j< 8; j++){
			board[i][j].set_state(0);
		}
	}
	board[3][3].set_state(2);
	board[3][4].set_state(1);
	board[4][3].set_state(1);
	board[4][4].set_state(2);
	game::restart();
}

void Othello::display_status() const{  //Displays the current gameboard to command line
	int i = 0;
	int j = 0;
	std::cout << "     A       B       C       D       E       F       G       H    \n";
	std::cout << " ";
	for(j = 0; j < 8; j++){
		for(i = 0; i < 8; i ++){
			std::cout << "########";
		}
		std::cout << "#\n";
		std::cout << " ";
		for(i = 0; i < 8; i ++){
			std::cout << RESET << "#" << B_GREEN << "       ";
		}
		std::cout << RESET << "#\n";
		std::cout << j+1;
		for(i = 0; i < 8; i ++){
			if(board[j][i].state() == 1){
				std::cout << RESET << "#" << B_GREEN << "  " << B_BLACK << "   " << B_GREEN << "  ";
			}
			else if(board[j][i].state() == 2){
				std::cout << RESET << "#" << B_GREEN << "  " << B_WHITE << "   " << B_GREEN << "  ";
			}
			else{
				std::cout << RESET << "#" << B_GREEN << "       ";
			}
		}
		std::cout << RESET << "#\n";
		std::cout << " ";
		for(i = 0; i < 8; i ++){
			if(board[j][i].state() == 1){
				std::cout << RESET << "#" << B_GREEN << "  " << B_BLACK << "   " << B_GREEN << "  ";
			}
			else if(board[j][i].state() == 2){
				std::cout << RESET << "#" << B_GREEN << "  " << B_WHITE << "   " << B_GREEN << "  ";
			}
			else{
				std::cout << RESET << "#" << B_GREEN << "       ";
			}
		}
		std::cout << RESET << "#\n";
		std::cout << " ";
		for(i = 0; i < 8; i ++){
			std::cout << RESET << "#" << B_GREEN << "       ";
		}
		std::cout << RESET << "#\n";
		std::cout << " ";
	}
	for(i = 0; i < 8; i++){
		std::cout << "########";
	}
	std::cout << "#\n";
}

bool Othello::is_legal(const std::string& move) const{  //Checks if a move is legal
	queue<string> test;
	if(move == "Pass"){
		compute_moves(test);
		if(test.front() == "Pass"){
			return true;
		}
		else{
			return false;
		}
	}
	int i = toupper(move[0])-'A';
	int j = (move[1]-'1');
	if(((0 <= i)&&(i <= 8)) && ((0 <= j)&&(j <= 8))){
		if(board[j][i].state() != 0){
			return false;
		}
		else if(north(j, i)||noreast(j, i)||east(j, i)||soueast(j, i)||south(j, i)||souwest(j, i)||west(j, i)||norwest(j, i)){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}
}

game* Othello::clone() const{  //Makes a copy of the game
	return new Othello(*this);
}

bool Othello::north(int r, int c) const{  //Checks north
	--r;
	if(r < 0 || r > 7 || c < 0 || c > 7){
		return false;
	}
	int t = 1;
	if(moves_completed()%2 != 0){
		t = 2;
	}
	if(board[r][c].state() == 0 || board[r][c].state() == t){
		return false;
	}
	else{
		--r;
		while(r >= 0){
			if(board[r][c].state() == 0){
				return false;
			}
			else if(board[r][c].state() == t){
				return true;
			}
			else{
				--r;
			}
		}
		return false;
	}
}

bool Othello::noreast(int r, int c) const{  //Checks north-east
	--r;
	++c;
	if(r < 0 || r > 7 || c < 0 || c > 7){
		return false;
	}
	int t = 1;
	if(moves_completed()%2 != 0){
		t = 2;
	}
	if(board[r][c].state() == 0 || board[r][c].state() == t){
		return false;
	}
	else{
		--r;
		++c;
		while(r >= 0 && c <= 8){
			if(board[r][c].state() == 0){
				return false;
			}
			else if(board[r][c].state() == t){
				return true;
			}
			else{
				--r;
				++c;
			}
		}
		return false;
	}
}

bool Othello::east(int r, int c) const{  //Checks east
	++c;
	if(r < 0 || r > 7 || c < 0 || c > 7){
		return false;
	}
	int t = 1;
	if(moves_completed()%2 != 0){
		t = 2;
	}
	if(board[r][c].state() == 0 || board[r][c].state() == t){
		return false;
	}
	else{
		++c;
		while(c <= 8){
			if(board[r][c].state() == 0){
				return false;
			}
			else if(board[r][c].state() == t){
				return true;
			}
			else{
				++c;
			}
		}
		return false;
	}
}

bool Othello::soueast(int r, int c) const{  //Checks south-east
	++r;
	++c;
	if(r < 0 || r > 7 || c < 0 || c > 7){
		return false;
	}
	int t = 1;
	if(moves_completed()%2 != 0){
		t = 2;
	}
	if(board[r][c].state() == 0 || board[r][c].state() == t){
		return false;
	}
	else{
		++r;
		++c;
		while(r <= 8 && c <= 8){
			if(board[r][c].state() == 0){
				return false;
			}
			else if(board[r][c].state() == t){
				return true;
			}
			else{
				++r;
				++c;
			}
		}
		return false;
	}
}

bool Othello::south(int r, int c) const{  //Checks south
	++r;
	if(r < 0 || r > 7 || c < 0 || c > 7){
		return false;
	}
	int t = 1;
	if(moves_completed()%2 != 0){
		t = 2;
	}
	if(board[r][c].state() == 0 || board[r][c].state() == t){
		return false;
	}
	else{
		++r;
		while(r <= 8){
			if(board[r][c].state() == 0){
				return false;
			}
			else if(board[r][c].state() == t){
				return true;
			}
			else{
				++r;
			}
		}
		return false;
	}
}

bool Othello::souwest(int r, int c) const{  //Checks south-west
	++r;
	--c;
	if(r < 0 || r > 7 || c < 0 || c > 7){
		return false;
	}
	int t = 1;
	if(moves_completed()%2 != 0){
		t = 2;
	}
	if(board[r][c].state() == 0 || board[r][c].state() == t){
		return false;
	}
	else{
		++r;
		--c;
		while(r <= 8 && c >= 0){
			if(board[r][c].state() == 0){
				return false;
			}
			else if(board[r][c].state() == t){
				return true;
			}
			else{
				++r;
				--c;
			}
		}
		return false;
	}
}

bool Othello::west(int r, int c) const{  //Checks west
	--c;
	if(r < 0 || r > 7 || c < 0 || c > 7){
		return false;
	}
	int t = 1;
	if(moves_completed()%2 != 0){
		t = 2;
	}
	if(board[r][c].state() == 0 || board[r][c].state() == t){
		return false;
	}
	else{
		--c;
		while(c >= 0){
			if(board[r][c].state() == 0){
				return false;
			}
			else if(board[r][c].state() == t){
				return true;
			}
			else{
				--c;
			}
		}
		return false;
	}
}

bool Othello::norwest(int r, int c) const{  //Checks north-west
	--r;
	--c;
	if(r < 0 || r > 7 || c < 0 || c > 7){
		return false;
	}
	int t = 1;
	if(moves_completed()%2 != 0){
		t = 2;
	}
	if(board[r][c].state() == 0 || board[r][c].state() == t){
		return false;
	}
	else{
		--r;
		--c;
		while(r >= 0 && c >= 0){
			if(board[r][c].state() == 0){
				return false;
			}
			else if(board[r][c].state() == t){
				return true;
			}
			else{
				--r;
				--c;
			}
		}
		return false;
	}
}

bool Othello::is_game_over() const{  //Checks if the game has ended
	if(pass > 1){
		return true;
	}
	return false;
}

int Othello::evaluate() const{  //Determines the winner
	int h = 0;
	int c = 0;
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if(board[i][j].state() == 1){
				++h;
			}
			else if(board[i][j].state() == 2){
				++c;
			}
			else{}
		}
	}
	if(moves_completed()%2 == 0){
		return c-h;
	}
	else{
		return h-c;
	}
}

void Othello::compute_moves(std::queue<std::string>& moves) const{  //Gives a queue of all legal moves
	string m = "A1";
	for(int i = 0; i < 8; i++){
		m[1] = '1';
		for(int j = 0; j < 8; j++){
			if(is_legal(m)){
				moves.push(m);
			}
			++m[1];
		}
		++m[0];
	}
	if(moves.size() == 0){
		moves.push("Pass");
	}
	return;
}

}