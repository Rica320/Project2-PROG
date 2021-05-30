#ifndef MENU_H
#define MENU_H

// classes
#include "Game.h"
#include "Robot.h"
#include "LeaderBoard.h"
#include "Fail_Procedure.h"

// stl headers
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

class Menu {
public:

    /**
    Shows the intro of the game.
    @return (none)
    */
    void showIntro() const;

    /**
    Manages the options of the initial menu.
    @return (none)
    */
    void menuLoop();

    /**
    Tries to open a file.
    @param file - the file's name
    @return bool indicating success of the opening
    */
    static bool tryOpen(const std::string& file);

    /**
    Creates the name of the maze file, to be searched.
    @param file_to_open - the number of the maze
    @return the full name of the maze file
    */
    static std::string map_int_to_maze(unsigned short int file_to_open); // static if somebody wants to use it outside

    /**
    Creates the name of the winners file, to be searched.
    @param file_to_open - the number of the maze
    @return the full name of the winners file
    */
    static std::string map_int_to_mazeWin(unsigned short int file_to_open);
    
    /**
    Asks the user about the maze number until getting a valid number 
    (number of an existing file or back to main menu).
    @return the number of the maze or NULL (0) to go to menu
    */
    static unsigned short getValidMaze();

    /**
    Asks the name of the winner until it is valid (max. 15 chars).
    @return valid winner name
    */
    static std::string getPlayerName();

private:

    /**
    Displays the rules of the game.
    @return (none)
    */
    void menu_Rules() const;

    /**
    Handles the game mode.
    @return (none)
    */
    void menu_Play() const;

    /**
    Asks the user which one is the maze he/she wants to see the winners of and
    shows the list of winners if file is found and is not empty, otherwise
    "empty list".
    @return (none)
    */
    static void menu_Winners();

    /**
    Adds name and time of the new winner to the winners file, sorts it in
    ascending order and shows it.
    @param file_num - the number of the maze
    @param time - the time the player took to win the game
    @return (none)
    */
    static void updateLeadersFile(unsigned short  int file_num, int time);
    // making it static gives the opportunity to update the leaderboard at any moment

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
	const std::string Rule_FILE = "RULES.TXT";
};

#endif