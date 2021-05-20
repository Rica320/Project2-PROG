#ifndef POST_H
#define POST_H

#include "Position.h"

class Post {
public:
	Post(int row, int col, char type);
	Post() = default;
	int getRow() const;
	int getCol() const;
	char getSymbol() const; // get char representation of Post
	bool isElectrified() const;
	bool isExit() const;
	//other methods - A METHOD TO TELL IF IT IS A EXIT DOOR
private:
	int row, col;
	char type; // '*' - electrified; '+'- non-electrified
	// other attributes (?)
};

#endif