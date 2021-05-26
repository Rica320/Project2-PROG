//
// Created by ricar on 26/05/2021.
//

#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <tuple>
#include <algorithm>

struct Person {
    std::string name;
    int time;
};

class LeaderBoard {
public:
    explicit LeaderBoard(const std::string& Maze_file);
    ~LeaderBoard();
    void addToLeaderBoard(Person& aPerson); // NOT const(par.) only because we could implement methods to delete lines
    void showLeaderBoard() const;
    void sortLeaderBoard();
    static short MAX_NAME_LENGTH;
    static short SPACE_BETWEEN_NAME_TIME;
    static short TIME_WIDTH;
private:
    std::string Maze_file;
    std::vector<Person> entries;
};

inline std::ostream& operator <<(std::ostream& os, const Person& right) {
    os << std::left << std::setw(LeaderBoard::MAX_NAME_LENGTH) << right.name
       << " - " << std::right << std::setw(LeaderBoard::TIME_WIDTH)<< right.time;
    return os;
}
inline bool operator <(const Person& left, const Person& right) {
    if(left.time != right.time)
        return left.time < right.time;
    return left.name < right.name;
}

#endif //LEADERBOARD_H
