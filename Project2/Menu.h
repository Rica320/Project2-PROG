#ifndef MENU_H
#define MENU_H

// classes
#include "Game.h"
#include "Robot.h"

// stl headers
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

class Menu {
public:
	void showIntro();
	void menuLoop();
    static bool tryOpen(const std::string& file);
    static std::string map_int_to_maze(unsigned short int file_to_open);
    static std::string map_int_to_mazeWin(unsigned short int file_to_open);
    static unsigned short getValidMaze();
private:
    void menu_op1() const;
    static void menu_op2();
    static void menu_op3();
private:
	const std::string GAME_INTRO = (
            ".______        ______   .______     ______   .___________.    _______.       _______      ___      .___  ___.  _______ \n"
            "|   _  \\      /  __  \\  |   _  \\   /  __  \\  |           |   /      |       /  _____|    /   \\     |   \\/   | |   ____|\n"
            "|  |_)  |    |  |  |  | |  |_)  | |  |  |  | `---|  |----`  |   (----`     |  |  __     /  ^  \\    |  \\  /  | |  |__   \n"
            "|      /     |  |  |  | |   _  <  |  |  |  |     |  |        \\   \\         |  | |_ |   /  /_\\  \\   |  |\\/|  | |   __|  \n"
            "|  |\\  \\----.|  `--'  | |  |_)  | |  `--'  |     |  |    .----)   |        |  |__| |  /  _____  \\  |  |  |  | |  |____ \n"
            "| _| `._____| \\______/  |______/   \\______/      |__|    |_______/          \\______| /__/     \\__\\ |__|  |__| |_______| \n\n"

    );
	const std::string Rule_FILE = "RULES.TXT";
};

#endif