// T04_G07

#include "LeaderBoard.h"

const unsigned int LeaderBoard::MAX_NAME_LENGTH = 15;
const unsigned int LeaderBoard::SPACE_BETWEEN_NAME_TIME = 2;
const unsigned int LeaderBoard::TIME_WIDTH = 4;

//------------------------------------------------------------------------
LeaderBoard::LeaderBoard(const std::string& leaders_file) {
	std::ifstream ifs(leaders_file);
	this->Maze_file = leaders_file;
	if (ifs.fail())
		return;

	ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore header
	ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	while (!ifs.eof()) {
		std::string line, aName;
		int aTime;

		getline(ifs, line);
		aName = line.substr(0, MAX_NAME_LENGTH);
		aTime = stoi(line.substr(MAX_NAME_LENGTH + SPACE_BETWEEN_NAME_TIME));

		Person aPerson{ aName,aTime };
		entries.push_back(aPerson);
	}
}

//------------------------------------------------------------------------
LeaderBoard::~LeaderBoard() {
	std::ofstream ofs(Maze_file, std::ofstream::trunc);

	ofs << "Player          - Time\n"
		<< "----------------------";

	for (const auto& i : entries)
		ofs << '\n' << i;
	ofs.close();
}

//------------------------------------------------------------------------
void LeaderBoard::addToLeaderBoard(Person& aPerson) {
	entries.push_back(aPerson);
}

//------------------------------------------------------------------------
void LeaderBoard::showLeaderBoard() const {
	std::cout << "\t\tPlayer          - Time\n"
		<< "\t\t----------------------";
	
	if (entries.empty()) {
		std::cout << "\n\t\tEmpty list!!! No Winners yet\n";
	}

	for (const auto& i : entries) {
		std::cout << '\n' << i;
	}
	std::cout << '\n' << std::endl;
}

//------------------------------------------------------------------------
void LeaderBoard::sortLeaderBoard() {
	std::sort(entries.begin(), entries.end());
}