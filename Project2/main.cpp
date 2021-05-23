// T04_G07.cpp
// Project2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Game.h"
#include <fstream>
#include <sstream>
#include <iomanip>

void rules();
void playGame();
void showWinners();

unsigned short getValidMaze();

std::string map_int_to_maze(unsigned short int file_to_open);
bool tryOpen(std::string file);


int main()
{

	// 
	// NOTA: FAZER UMA CLASS MENU ????
	//
	unsigned short int mode;
	const unsigned short NOT_VALID_INPUT = 99;

	const std::string GAME_INTRO(
		".______        ______   .______     ______   .___________.    _______.       _______      ___      .___  ___.  _______ \n"
		"|   _  \\      /  __  \\  |   _  \\   /  __  \\  |           |   /      |       /  _____|    /   \\     |   \\/   | |   ____|\n"
		"|  |_)  |    |  |  |  | |  |_)  | |  |  |  | `---|  |----`  |   (----`     |  |  __     /  ^  \\    |  \\  /  | |  |__   \n"
		"|      /     |  |  |  | |   _  <  |  |  |  |     |  |        \\   \\         |  | |_ |   /  /_\\  \\   |  |\\/|  | |   __|  \n"
		"|  |\\  \\----.|  `--'  | |  |_)  | |  `--'  |     |  |    .----)   |        |  |__| |  /  _____  \\  |  |  |  | |  |____ \n"
		"| _| `._____| \\______/  |______/   \\______/      |__|    |_______/          \\______| /__/     \\__\\ |__|  |__| |_______| \n\n"

	);
	std::cout << GAME_INTRO;

	do
	{
		std::cout << "\t\t1) Rules\n\t\t2) Play\n\t\t3) Winners\n\t\t0) Exit\n\t\t\t\t\t\t\t\t\t\t\t";
		std::cin >> mode;

		if (std::cin.fail() || std::cin.get() != '\n')
		{
			mode = NOT_VALID_INPUT;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		switch (mode) {
		case 1:
			rules();
			break;
		case 2:
			playGame();
			break;
		case 3:
			//show the list of winners (or the message "empty list" if there are no winners, yet).
			showWinners();
			break;
		case 0:
			break;
		default:
			std::cerr << "Not a valid option. Try again !!\a\n";
			break;
		}


	} while (mode != 0);

	return 0;
}

//------------------------------------------------------------------------
/**
Displays the rules of the game.
@return (none)
*/
void rules() {
	std::ifstream ifs;

	ifs.open("RULES.TXT");
	
	if (ifs.fail())
	{
		ifs.close();
		std::cerr << "Error: could not load rules\n";
		return;
	}
	
	std::string line;
	
	while (!ifs.eof())
	{
		getline(ifs, line);
		std::cout << line << std::endl;
	}
}

//------------------------------------------------------------------------
/**
Starts the game mode.
@return (none)
*/
void playGame(){
	unsigned short int file_num = getValidMaze();

	if (!file_num)
		return;

	Game game(map_int_to_maze(file_num));

	bool result = game.play(); //result: true -> won; false -> lost
}

//------------------------------------------------------------------------
/**
Asks the user about the maze to open until getting a valid file number
(number of an existing file or back to main menu)
@return the number of the maze or NULL (0) to go to menu
*/
unsigned short getValidMaze()
{
	const short MAX_MAZE_NUMBER = 99;

	unsigned short f_num;
	std::string mazeFileName;

	bool validInput;

	do
	{
		// repeat this until the corresponding maze file is found or the user input is 0 (show menu again)

		std::cout << "\t\tTell us the maze to use (0 to go to menu)\n\t\t\t\t\t\t\t\t\t\t\t";
		std::cin >> f_num;

		validInput = true;

		if (std::cin.fail() || std::cin.get() != '\n') {

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			validInput = false;
			std::cerr << "\t\tNot a valid Maze number. Try again !!\a\n\n";
		}
		else {
			if (!f_num)
				return f_num;

			else if (f_num > MAX_MAZE_NUMBER) {
				validInput = false;
				std::cerr << "\t\tNot a valid Maze number (1-99). Try again !!\a\n\n";
			}
			mazeFileName = map_int_to_maze(f_num);
		}
	} while (!validInput || !tryOpen(mazeFileName));
	return f_num;
}

//------------------------------------------------------------------------
/**
Creates the name of the maze file, to be searched.
@param file_to_open - the number of the maze
@return the full name of the maze file
*/
std::string map_int_to_maze(unsigned short int file_to_open) {

	const unsigned int FNUM_WIDTH = 2; // width of the file number

	std::ostringstream oss;

	oss << "MAZE_" << std::setw(FNUM_WIDTH) << std::setfill('0') << file_to_open << ".txt";

	return oss.str();
}

//------------------------------------------------------------------------
/**
Tries to open the file of the maze.
@param file - the file name of the maze to play
@return bool indicating success of the opening
*/
bool tryOpen(std::string file)
{
	std::ifstream ifs;

	ifs.open(file);

	if (ifs.fail())
	{
		std::cerr << "\t\tFile " << file << " not found\a\n" << std::endl;
		return false;
	}
	return true;
}

//------------------------------------------------------------------------
void showWinners()
{
	//option 3 in menu
}