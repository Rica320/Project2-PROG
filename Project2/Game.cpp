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
			}
		}
		ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	ifs.close();

}


void Game::showGameDisplay() const { // just an experiment (shows posts)
	int a{};
	for (const auto& i : maze.getPosts()) {
		if (i.first.row > a) {
			a += 1;
			std::cout <<std::endl << i.second.getSymbol();
		}
		else {
			std::cout << i.second.getSymbol();
		}
	}
}


/*void Game::showGameDisplay() const { //dá erro

	int numRobots = 0; //remove after create map

	for (int i = 0; i < maze.getnumRows(); i++)
	{
		for (int j = 0; j < maze.getnumCols(); j++)
		{
			Position pos = {i,j};

			if (maze.getPosts().find(pos) != maze.getPosts().end()) {
				std::cout << maze.getPosts().find(pos)->second.getSymbol();
			}
			else if (pos.row == player.getRow() && pos.col == player.getCol()) {
				std::cout << player.getSymbol();
			}
			else //create robots map?
			{
				bool var = false;
				while (numRobots < robots.size())
				{
					if (robots[numRobots].getRow()==pos.row && robots[numRobots].getCol() == pos.col) {
						
						std::cout << robots[numRobots].getSymbol();
						var = true;
					}
					numRobots++;
				}
				if (!var) std::cout << ' ';
			}
		}
		std::cout << std::endl;
	}
}*/

bool Game::play() {
	showGameDisplay();

	return player.isAlive(); //&& won (reached portal)
}