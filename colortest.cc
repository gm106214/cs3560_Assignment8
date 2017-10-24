/*
Gavin McGee
gm106214@ohio.edu
CS2401
11/14/16
*/
//File to test the colors.h file operations.

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "colors.h"

int main(){  //Main function
	int i = 0;
	int j = 0;
	std::cout << "    A       B       C       D       E       F       G       H    \n";
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
			std::cout << RESET << "#" << B_GREEN << "  " << B_BLACK << "   " << B_GREEN << "  ";
		}
		std::cout << RESET << "#\n";
		std::cout << " ";
		for(i = 0; i < 8; i ++){
			std::cout << RESET << "#" << B_GREEN << "  " << B_BLACK << "   " << B_GREEN << "  ";
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
	return 0;
}