#include "Game.h"
Game::Game(const std::string& filename) { // está a funcionar direito
	std::ifstream ifs(filename);

	int Nrows, Ncols;
	char garbage, element;

	ifs >> Nrows >> garbage >> Ncols;

	Maze maze_temp(Nrows, Ncols);
	this->maze = maze_temp;

	ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Maybe useless

	for (int i = 0; i < Nrows; i++)
	{
		for (int j = 0; j < Ncols; j++)
		{
			element = ifs.get();

			if (element == '*' || element == '+' || element == 'O') {
				Post aPost(i, j, element);
				Position pos{ i, j };
				maze.addPost(aPost, pos);
			}else if (element == 'H') {
				Player thePlayer(i, j, element);
				player = thePlayer;
			}else if (element == 'R') {
				Robot aRobot(i, j);
				robots.push_back(aRobot);
			}
		}
		ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	ifs.close();

}

void Game::showGameDisplay() const { // just an experiment
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

bool Game::play() {
	showGameDisplay();

	return player.isAlive();
}