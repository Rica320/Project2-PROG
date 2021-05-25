#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>
#include "Game.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Robot.h"
#include <string>

class Menu {
public:
	void showName();
	void askMode();
	void menu_op1();
	void menu_op2();
	unsigned short getValidMaze();
	std::string map_int_to_maze(unsigned short int file_to_open);
	bool tryOpen(std::string file);
	void menu_op3();
	std::string map_int_to_mazeWin(unsigned short int file_to_open);

private:
	unsigned short int mode;
	const std::string GAME_INTRO(
		".______        ______   .______     ______   .___________.    _______.       _______      ___      .___  ___.  _______ \n"
		"|   _  \\      /  __  \\  |   _  \\   /  __  \\  |           |   /      |       /  _____|    /   \\     |   \\/   | |   ____|\n"
		"|  |_)  |    |  |  |  | |  |_)  | |  |  |  | `---|  |----`  |   (----`     |  |  __     /  ^  \\    |  \\  /  | |  |__   \n"
		"|      /     |  |  |  | |   _  <  |  |  |  |     |  |        \\   \\         |  | |_ |   /  /_\\  \\   |  |\\/|  | |   __|  \n"
		"|  |\\  \\----.|  `--'  | |  |_)  | |  `--'  |     |  |    .----)   |        |  |__| |  /  _____  \\  |  |  |  | |  |____ \n"
		"| _| `._____| \\______/  |______/   \\______/      |__|    |_______/          \\______| /__/     \\__\\ |__|  |__| |_______| \n\n"

	);
};

#endif