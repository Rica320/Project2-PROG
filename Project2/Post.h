#ifndef POST_H
#define POST_H

#include "Position.h"
#include "Game_Object.h"

class Post : public Game_Object{
public:
	Post( int row, int col, char symbol) : Game_Object(row, col, symbol) {};
	Post() = default;

	/**
	Returns if the post is electrified or not
	@return true if is, false otherwise
	*/
	bool isElectrified() const;

	/**
	Returns if that maze post is actually an exit
	@return true if is an exit, false otherwise
	*/
	bool isExit() const;

};


#endif