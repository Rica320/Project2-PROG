#include "Game.h"

//------------------------------------------------------------------------
Game::Game(const std::string& filename) { 
	std::ifstream ifs(filename);

	int nRows, nCols;
	char element;

	ifs >> nRows; ifs.ignore(100, 'x'); ifs >> nCols;

	Maze maze_temp(nRows, nCols);
	this->maze = maze_temp;

	ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Maybe useless

	for (int i = 0; i < nRows; i++)
	{
		for (int j = 0; j < nCols; j++)
		{
			element = (char)ifs.get();

			if (element == '*' || element == '+' || element == 'O') {
				Post aPost( i, j, element);
				Position pos{ i, j };
				maze.addPost(aPost, pos);
			} else if (element == 'H') {
				Player thePlayer(i, j, element);
				player = thePlayer;
			} else if (element == 'R' || element == 'r') {
				Robot aRobot(i, j, element);
				robots.push_back(aRobot);
			}
		}
		ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	ifs.close();
}

//------------------------------------------------------------------------
void Game::showGameDisplay() const {

	char c;

	for (int i = 0; i < maze.getnumRows(); i++)
	{
		std::cout << "\t\t";
		for (int j = 0; j < maze.getnumCols(); j++)
		{
			Position pos = {i,j};
			
			c = inPosRobot(pos);

			// Note: order of display is important as we
			//       want first to see the player and the 
			//       robots and only then (if there is none)
			//       the posts and ' ' space.

			if (pos == player.getPosition()) {
				std::cout << player.getSymbol();
			}
			else if (c != '\0')
			{
				std::cout << c; 
			}
			else if (maze.getPosts().find(pos) != maze.getPosts().end()){
				std::cout << maze.getPosts().find(pos)->second.getSymbol();
			}
			else
			{
				std::cout << ' '; // no object there
			}
		}
		std::cout << "\n";
	}
}

//------------------------------------------------------------------------
bool Game::play() {

	showGameDisplay();

	while (player.isAlive())
	{
		char move = getMove();

		player.move(ctom(move));

		if (collidePosts(player)) { 
			showGameDisplay();
			return player.isAlive(); //won or lost
		}

		// check collidePlayer

		moveRobots();

		showGameDisplay();
	}

	return player.isAlive();
}

//------------------------------------------------------------------------
char Game::getMove() const{
	char move_key;
	bool valid;

	do
	{
		std::cout << "\t\tWhich move do you want to make?\n\t\t\t\t\t\t\t\t\t\t\t";
        std::cin >> move_key; std::cout << "\n"; // Just for space management

		move_key = (char)toupper(move_key);

		valid = validMove(move_key);

		if (std::cin.fail() || std::cin.peek() != '\n') {
			isInvalid();
			valid = false;
		}

		if (!valid) {
			std::cerr << "\t\tNot a valid move!!!\n";
		}

	} while (!valid);

	return move_key;
}

//------------------------------------------------------------------------
bool Game::validMove(char c) const {

	std::map<Position, Post> posts = maze.getPosts();
	std::map<Position, Post>::iterator iter;

	bool validMove =
		(c == 'Q' || c == 'W' || c == 'E' ||
			c == 'A' || c == 'S' || c == 'D' ||
			c == 'Z' || c == 'X' || c == 'C');

	if (!validMove)
		return false;

	Movement playerChange = ctom(c);
	Position playerNewPos = player.getPosition() + playerChange;

	iter = posts.find(playerNewPos);

	if (iter != posts.end() && !iter->second.isElectrified() && !iter->second.isExit()) //iter != posts.end() evaluated first
		return false;

	if (std::any_of(robots.begin(),robots.end(), [playerNewPos](Robot i){return i.getPosition() == playerNewPos && !i.isAlive();}))
        return false;

    return true;
}

//------------------------------------------------------------------------
Movement Game::ctom(char c) {
	// map char to index movement
    // TODO MAKE THIS SHORTER
	Movement mov{ 0,0 };

	static const short int PREV = -1; // to move to the previous line or column
	static const short int FOLL = 1; // to move to the following line or column
	static const short int SAME = 0; // to stay in the same line or column

	switch (c) {
	case 'Q':
		mov.dRow = PREV; // the change in row
		mov.dCol = PREV; // the change in col
		break;
	case 'W':
		mov.dRow = PREV;
		mov.dCol = SAME;
		break;
	case 'E':
		mov.dRow = PREV;
		mov.dCol = FOLL;
		break;
	case 'A':
		mov.dRow = SAME;
		mov.dCol = PREV;
		break;
	case 'S':
		mov.dRow = SAME;
		mov.dCol = SAME;
		break;
	case 'D':
		mov.dRow = SAME;
		mov.dCol = FOLL;
		break;
	case 'Z':
		mov.dRow = FOLL;
		mov.dCol = PREV;
		break;
	case 'X':
		mov.dRow = FOLL;
		mov.dCol = SAME;
		break;
	case 'C':
		mov.dRow = FOLL;
		mov.dCol = FOLL;
		break;
	default:
		std::cerr << "\t\tHouston, we have a big big problem" << std::endl;
		exit(1);
	}
	return mov;
}

//------------------------------------------------------------------------
bool Game::collidePlayer(Robot &robot) {
	if (robot.getPosition() == player.getPosition()) {
		player.setAsDead();
		return true;
	}
	return false;
}

//------------------------------------------------------------------------
void Game::moveRobots() {

	static const short int PREV = -1; // to move to the previous line or column
	static const short int FOLL = 1; // to move to the following line or column
	static const short int SAME = 0; // to stay in the same line or column

	std::map<Position, Post> posts = maze.getPosts();
	std::map<Position, Post>::iterator iter;

	for (auto& robot : robots) {
		if (robot.isAlive()) {
			int lineMove = (player.getRow() >= robot.getRow()) ? ((player.getRow() == robot.getRow()) ? SAME : FOLL) : PREV;
			int colMove = (player.getCol() >= robot.getCol()) ? ((player.getCol() == robot.getCol()) ? SAME : FOLL) : PREV;


			Movement dChange{ lineMove,colMove };
			Movement dInvChange{ -lineMove,-colMove };

			robot.move(dChange); // move robot

			if (collidePosts(robot)) { // if it collided with electrified post, reverse move
				robot.move(dInvChange);
				continue; // no need to check other type of collision
			}

            if (collidePlayer(robot))
                break;
            
			collideRobots(robot);

		}
	}
}

//------------------------------------------------------------------------
void Game::collideRobots(Robot& robot) {
	for (auto& aRobot : robots) {
		if (aRobot.getID() != robot.getID() && aRobot.getPosition() == robot.getPosition()) {
			// checking if the 2 robots are not the same and if they are in the same position

			robot.setAsDead();
			aRobot.setAsDead();
			return;
		}
	}
}

//------------------------------------------------------------------------
char Game::inPosRobot(Position apos) const {
	for (auto& i : robots) {
		if (i.getPosition() == apos)
			return i.getSymbol();
	}
	return '\0'; // returns NULL char
}
