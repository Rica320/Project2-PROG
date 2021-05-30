// T04_G07

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
    std::string name; //name of the winner
    int time; //time the player took to win
};

class LeaderBoard {
public:

    /**
    Creates leaderboard object, loading all the winners to a vector if winners file not empty.
    @param leaders_file - winners file name
    */
    explicit LeaderBoard(const std::string& leaders_file);

    /**
    Stores all the winners in a file before destruction.
    */
    ~LeaderBoard();

    /**
    Adds a new winner to the leaderboard.
    @param aPerson - winner to add
    @return (none)
    */
    void addToLeaderBoard(Person& aPerson);

    /**
    Displays the list of winners if not empty, else "empty list".
    @return (none)
    */
    void showLeaderBoard() const;

    /**
    Sorts leaders in ascending order of time.
    */
    void sortLeaderBoard();

    static const unsigned int MAX_NAME_LENGTH;
    static const unsigned int SPACE_BETWEEN_NAME_TIME;
    static const unsigned int TIME_WIDTH;

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
