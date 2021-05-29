#ifndef MENU_H
#define MENU_H

// classes
#include "Game.h"
#include "Robot.h"
#include "LeaderBoard.h"

// stl headers
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

class Menu {
public:
	void showIntro() const;
	void menuLoop();
    static bool tryOpen(const std::string& file);
    static std::string map_int_to_maze(unsigned short int file_to_open); // static if somebody wants to use it outside
    static std::string map_int_to_mazeWin(unsigned short int file_to_open);
    static unsigned short getValidNum();
    static std::string getPlayerName();
private:
    void menu_op1() const;
    void menu_op2() const;
    static void menu_op3();
    static void updateLeadersFile(unsigned short  int file_num, int time);
    // making it static gives the opportunity to update the file at any moment
private:
	const std::string GAME_INTRO = (
            ".______        ______   .______     ______   .___________.    _______.       _______      ___      .___  ___.  _______ \n"
            "|   _  \\      /  __  \\  |   _  \\   /  __  \\  |           |   /      |       /  _____|    /   \\     |   \\/   | |   ____|\n"
            "|  |_)  |    |  |  |  | |  |_)  | |  |  |  | `---|  |----`  |   (----`     |  |  __     /  ^  \\    |  \\  /  | |  |__   \n"
            "|      /     |  |  |  | |   _  <  |  |  |  |     |  |        \\   \\         |  | |_ |   /  /_\\  \\   |  |\\/|  | |   __|  \n"
            "|  |\\  \\----.|  `--'  | |  |_)  | |  `--'  |     |  |    .----)   |        |  |__| |  /  _____  \\  |  |  |  | |  |____ \n"
            "| _| `._____| \\______/  |______/   \\______/      |__|    |_______/          \\______| /__/     \\__\\ |__|  |__| |_______| \n\n"

    );
    const std::string WIN_MESSAGE = (
        "\t\t____    ____  __    ______ .___________.  ______   .______     ____    ____     __   __   __  \n"
        "\t\t\\   \\  /   / |  |  /      ||           | /  __  \\  |   _  \\    \\   \\  /   /    |  | |  | |  | \n"
        "\t\t \\   \\/   /  |  | |  ,----'`---|  |----`|  |  |  | |  |_)  |    \\   \\/   /     |  | |  | |  | \n"
        "\t\t  \\      /   |  | |  |         |  |     |  |  |  | |      /      \\_    _/      |  | |  | |  | \n"
        "\t\t   \\    /    |  | |  `----.    |  |     |  `--'  | |  |\\  \\----.   |  |        |__| |__| |__| \n"
        "\t\t    \\__/     |__|  \\______|    |__|      \\______/  | _| `._____|   |__|        (__) (__) (__) \n\n"
    );

    //const short SPACE_BETWEEN_NAME_TIME;
	const std::string Rule_FILE = "RULES.TXT";
};

#endif