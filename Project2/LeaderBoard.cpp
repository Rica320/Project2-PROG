//
// Created by ricar on 26/05/2021.
//

#include "LeaderBoard.h"

#include <utility>

short LeaderBoard::MAX_NAME_LENGTH = 15;
short LeaderBoard::SPACE_BETWEEN_NAME_TIME = 2;
short LeaderBoard::TIME_WIDTH = 4;

LeaderBoard::LeaderBoard(std::string Maze_file) {
    std::ifstream ifs(Maze_file);
    this->Maze_file = std::move(Maze_file);
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

        Person aPerson{aName,aTime};
        entries.push_back(aPerson);
    }
}

LeaderBoard::~LeaderBoard() {
    std::ofstream ofs(Maze_file, std::ofstream::trunc);

    ofs << "Player          - Time\n"
        << "----------------------"; // Could make this disappear out << header

    for(const auto &i: entries)
        ofs << '\n' << i;
    ofs.close();
}

void LeaderBoard::addToLeaderBoard(Person &aPerson) {
    entries.push_back(aPerson);
}

void LeaderBoard::showLeaderBoard() const {

    std::cout << "Player          - Time\n"
        << "----------------------"; // Could make this disappear out << header

    for (const auto &i: entries) {
        std::cout << '\n' << i;
    }
    std::cout << '\n' << std::endl; // flush
}

void LeaderBoard::sortLeaderBoard() {
    std::sort (entries.begin(), entries.end());
}