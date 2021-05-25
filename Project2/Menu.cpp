#include "Menu.h"

void Menu::showName() {
	std::cout << GAME_INTRO;
}

void Menu::askMode() {

	const unsigned short NOT_VALID_INPUT = 99;

	do {

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
			menu_op1();
			break;
		case 2:
			menu_op2();
			Robot::resetRobotCounter();
			break;
		case 3:
			//show the list of winners (or the message "empty list" if there are no winners, yet).
			menu_op3();
			break;
		case 0:
			break;
		default:
			std::cerr << "Not a valid option. Try again !!\a\n";
			break;
		}

	} while (mode != 0);
}

//------------------------------------------------------------------------
/**
Displays the rules of the game.
@return (none)
*/
void Menu::menu_op1() {
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
void Menu::menu_op2() {
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
unsigned short Menu::getValidMaze()
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
std::string Menu::map_int_to_maze(unsigned short int file_to_open) {

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
bool Menu::tryOpen(std::string file)
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
void Menu::menu_op3() {
	const short MAX_MAZE_NUMBER = 99;
	unsigned short maze;
	bool isValid;

	do
	{

		std::cout << "\t\tWhat is the maze from which you want to see the winners? (0 to go back)\n\t\t\t\t\t\t\t\t\t\t\t";
		std::cin >> maze;

		isValid = true;

		if (std::cin.fail() || std::cin.get() != '\n') {

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			isValid = false;
			std::cerr << "\t\tNot a valid Maze number. Try again !!\a\n\n";
		}
		else {
			if (!maze)
				return;

			else if (maze > MAX_MAZE_NUMBER) {
				isValid = false;
				std::cerr << "\t\tNot a valid Maze number (1-99). Try again !!\a\n\n";
			}
		}
	} while (!isValid);

	std::string winFileName = map_int_to_mazeWin(maze);
	if (!tryOpen(winFileName))
		std::cerr << "empty list\n"; //there are no winners yet
	else
		//showFileContent();
}
//------------------------------------------------------------------------
std::string Menu::map_int_to_mazeWin(unsigned short int file_to_open) {

	const unsigned int FNUM_WIDTH = 2; // width of the file number

	std::ostringstream oss;

	oss << "MAZE_" << std::setw(FNUM_WIDTH) << std::setfill('0') << file_to_open << "_WINNERS.txt";

	return oss.str();
}