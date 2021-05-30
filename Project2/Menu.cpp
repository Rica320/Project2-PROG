#include "Menu.h"

//------------------------------------------------------------------------
void Menu::showIntro() const{
	std::cout << GAME_INTRO;
}

//------------------------------------------------------------------------
void Menu::menuLoop() {

	const unsigned short NOT_VALID_INPUT = 99;
	unsigned short int mode;
	enum Modes{Exit, Rules , Play, Winners};

	do {

		std::cout << "\t\t1) Rules\n\t\t2) Play\n\t\t3) Winners\n\t\t0) Exit\n\t\t\t\t\t\t\t\t\t\t\t";
		std::cin >> mode; std::cout << "\n"; // Just for space management

		if (std::cin.fail() || std::cin.get() != '\n')
		{
			isInvalid();
			mode = NOT_VALID_INPUT;	
		}

		switch (mode) {
		case Rules:
            menu_Rules();
			break;
		case Play:
            menu_Play();
			break;
		case Winners:
            menu_Winners();
			break;
		case Exit:
			break;
		default:
			std::cerr << "\t\tNot a valid option. Try again !!\n";
			break;
		}

	} while (mode != 0);
}

//------------------------------------------------------------------------
void Menu::menu_Rules() const{
    if (!tryOpen(Rule_FILE))
        return;

	std::ifstream ifs;

	ifs.open(Rule_FILE);

	std::string line;

	while (!ifs.eof())
	{
		getline(ifs, line);
		std::cout << line << std::endl;
	}
}

//------------------------------------------------------------------------
void Menu::menu_Play() const{
	unsigned short int file_num = getValidMaze();

	if (!file_num)
		return;

	Game game(map_int_to_maze(file_num));

    time_t time_start = time(nullptr);
	bool result = game.play();
    time_t time_end = time(nullptr);
    time_t timePlayer = time_end - time_start;

    if (result) { 
		std::cout << WIN_MESSAGE;
        updateLeadersFile(file_num, (int) timePlayer);
    } else {
        std::cout << "\t\tGAME OVER! Better luck next time :)\n\n";
    }
	Robot::resetRobotCounter(); // prepare the id of the robots for the next game
}

//------------------------------------------------------------------------
unsigned short Menu::getValidMaze()
{
	static const short MAX_MAZE_NUMBER = 99;
	unsigned short f_num;
	std::string mazeFileName;
	bool validInput;

	do // repeat this until the corresponding maze file is found or the user input is 0 (show menu again)
	{
		std::cout << "\t\tTell us the maze to use (0 to go to menu)\n\t\t\t\t\t\t\t\t\t\t\t";
		std::cin >> f_num; std::cout << "\n"; // Just for space management

		validInput = true;

		if (std::cin.fail() || std::cin.get() != '\n') {

			isInvalid();
			validInput = false;
			std::cerr << "\t\tNot a valid Maze number. Try again !!\n\n";
		}
		else {
			if (!f_num) // f_num == 0
				return f_num;

			else if (f_num > MAX_MAZE_NUMBER) {
				validInput = false;
				std::cerr << "\t\tNot a valid Maze number (1-99). Try again !!\n\n";
			}
			mazeFileName = map_int_to_maze(f_num);
		}
	} while (!validInput || !tryOpen(mazeFileName));
	return f_num;
}

//------------------------------------------------------------------------
std::string Menu::map_int_to_maze(unsigned short int file_to_open) {

	static const unsigned int FNUM_WIDTH = 2; // width of the file number

	std::ostringstream oss;

	oss << "MAZE_" << std::setw(FNUM_WIDTH) << std::setfill('0') << file_to_open << ".txt";

	return oss.str();
}

//------------------------------------------------------------------------
bool Menu::tryOpen(const std::string& file)
{
	std::ifstream ifs;

	ifs.open(file);

	if (ifs.fail())
	{
		std::cerr << "\t\tFile " << file << " not found\n";
		return false;
	}
	return true;
}

//------------------------------------------------------------------------
void Menu::menu_Winners() {
	unsigned short int winner_file_num = getValidMaze();// if the Maze doesn't exist, the Maze_winners won't exist
	if (!winner_file_num)
		return;
    LeaderBoard leaderBoard(map_int_to_mazeWin(winner_file_num));
    leaderBoard.showLeaderBoard();
}

//------------------------------------------------------------------------
std::string Menu::map_int_to_mazeWin(unsigned short int file_to_open) {

	const unsigned int FNUM_WIDTH = 2; // width of the file number

	std::ostringstream oss;

	oss << "MAZE_" << std::setw(FNUM_WIDTH) << std::setfill('0') << file_to_open << "_WINNERS.txt";

	return oss.str();
}

//------------------------------------------------------------------------
void Menu::updateLeadersFile(unsigned short int file_num, int time) {

    LeaderBoard leaderBoard(map_int_to_mazeWin(file_num)); // maybe put this private

    Person newPerson{getPlayerName(), time};
    leaderBoard.addToLeaderBoard(newPerson);
    leaderBoard.sortLeaderBoard();
    leaderBoard.showLeaderBoard();
}

//------------------------------------------------------------------------
std::string Menu::getPlayerName() {
    std::string name;
    bool validLen;

    do
    {
        std::cout << "\t\tWhat's your name? (max.15)\n\t\t\t\t\t\t\t\t\t\t\t";
        std::cin >> std::ws;
        getline(std::cin, name); std::cout << "\n"; // Just for space management

		isExit();

        validLen = true;
        if (name.size() > (size_t)LeaderBoard::MAX_NAME_LENGTH)
        {
            validLen = false;
            std::cerr << "\t\tToo long!! Try again.\n";
        }
    } while (!validLen);

    return name;
}
