#ifndef POST_H
#define POST_H

#include "Position.h"
#include "Game_Object.h"

class Post : public Game_Object{
public:
	Post( int row, int col, char symbol) : Game_Object(row, col, symbol) {};
	Post() = default;
	bool isElectrified() const;
	bool isExit() const;
	//other methods - A METHOD TO TELL IF IT IS A EXIT DOOR
};


#endif