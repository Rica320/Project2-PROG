#include "Game.h"

Game::Game(const std::string& filename) { // está a funcionar direito
	std::ifstream ifs(filename);

	int nRows, nCols;
	char sep, element;

	ifs >> nRows >> sep >> nCols;

	Maze maze_temp(nRows, nCols);
	this->maze = maze_temp;

	ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Maybe useless

	for (int i = 0; i < nRows; i++)
	{
		for (int j = 0; j < nCols; j++)
		{
			element = ifs.get();

			if (element == '*' || element == '+' || element == 'O') {
				Post aPost(i, j, element);
				Position pos{ i, j };
				maze.addPost(aPost, pos);
			} else if (element == 'H') {
				Player thePlayer(i, j, element);
				player = thePlayer;
			} else if (element == 'R') {
				Robot aRobot(i, j);
				robots.push_back(aRobot);
				/*Position pos{ i, j };
				addRobot(pos, aRobot);*/
			}
		}
		ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	ifs.close();

	aliveRobots = Robot::getRobotCounter();
}

void Game::showGameDisplay() const {

	int indRobots = 0; 

	for (int i = 0; i < maze.getnumRows(); i++)
	{
		for (int j = 0; j < maze.getnumCols(); j++)
		{
			Position pos = {i,j};

			if (pos == player.getPosition()) {
				std::cout << player.getSymbol();
			}
			else if (char c = inPos(pos)) 
			{
				std::cout << c; 
			}
			else if (maze.getPosts().find(pos) != maze.getPosts().end()){
				std::cout << maze.getPosts().find(pos)->second.getSymbol();
			}
			else
			{
				std::cout << ' ';
			}
		}
		std::cout << "\n";
	}
}

bool Game::play() {

	showGameDisplay();

	while (player.isAlive() && aliveRobots)
	{
		char move = getMove();

		if (!move)
			return false;

		player.move(ctom(move));

		if (collidePosts(player)) { 
			showGameDisplay();
			return player.isAlive(); // DO
		}

		// check collide

		if (!moveRobots()) {
			showGameDisplay();
			break;
		}

		showGameDisplay();
	}

	return player.isAlive(); //&& won (reached portal) - no need
}

char Game::getMove() const{
	const char EXIT_GAME = NULL;
	char move_key;
	bool valid;

	do
	{
		std::cout << "\t\tWhich move do you want to make?\n\t\t\t\t\t\t\t\t\t\t\t";
		std::cin >> move_key;

		move_key = toupper(move_key);


		if (std::cin.fail() || std::cin.peek() != '\n') {
			if (std::cin.eof()) {
				std::cin.clear();
				return EXIT_GAME;
			}

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		valid = validMove(move_key);

		if (!valid) {
			std::cerr << "\t\tNot a valid move!!!\a\n";
		}

	} while (!valid);

	return move_key;
}

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
	Position playerNewPos = { player.getRow() + playerChange.dRow ,player.getCol() + playerChange.dCol };

	iter = posts.find(playerNewPos);

	if (iter != posts.end() && !iter->second.isElectrified() && !iter->second.isExit()) //iter != posts.end() evaluated first
		return false;

	for (const auto &i : robots) { // optimize later
		if (i.getPosition() == playerNewPos && !i.isAlive()) { // colide robot(dead)/player
			return false;
		}
	}
	
	return true;
}

Movement Game::ctom(char c) const {
	// map move to index change

	Movement mov{ 0,0 };

	const short int PREV = -1; // to move to the previous line or column
	const short int FOLL = 1; // to move to the following line or column
	const short int SAME = 0; // to stay in the same line or column

	switch (c) {
	case 'Q':
		mov.dRow = PREV; // the change in line
		mov.dCol = PREV; // the change in column
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
		break;
	}
	return mov;
}

bool Game::collide(Robot& robot, Player& player) {
	if (robot.getPosition() == player.getPosition()) {
		player.setAsDead();
		return true;
	}
	return false;
}

bool Game::moveRobots() {

	// to put in the collide section ...
	/*const int NO_DEATHS = 0;
	const int ONE_DEATH = 1;
	const int TWO_DEATHS = 2;*/

	const short int PREV = -1; // to move to the previous line or column
	const short int FOLL = 1; // to move to the following line or column
	const short int SAME = 0; // to stay in the same line or column

	std::map<Position, Post> posts = maze.getPosts();
	std::map<Position, Post>::iterator iter;

	for (auto& robot : robots) {
		if (robot.isAlive()) {
			int lineMove = (player.getRow() >= robot.getRow()) ? ((player.getRow() == robot.getRow()) ? SAME : FOLL) : PREV;
			int colMove = (player.getCol() >= robot.getCol()) ? ((player.getCol() == robot.getCol()) ? SAME : FOLL) : PREV;


			Movement dChange{ lineMove,colMove };
			Movement dInvChange{ -lineMove,-colMove };

			robot.move(dChange);
			if (collidePosts(robot)) { 
				robot.move(dInvChange);
				continue;
			}
			
			collideRobots(robot);

			if (collide(robot, player))
				break;
			
			//std::cout <<( iter != posts.end());
		}
	}

	return player.isAlive(); 
}

void Game::collideRobots(Robot& robot) {
	for (auto& arobot : robots) {
		if (arobot.getID() != robot.getID() && arobot.getPosition() == robot.getPosition()) {
			if (arobot.isAlive()) {
				aliveRobots -= 2; // 2 deaths- MAGIC NUMBER
			}
			else
			{
				aliveRobots --;
			}
			robot.setAsDead();
			arobot.setAsDead();
			return;
		}
	}

}

char Game::inPos(Position apos) const {
	for (auto& i : robots) {
		if (i.getPosition() == apos)
			return i.getSymbol();
	}
	return NULL;
}
