// T04_G07

#ifndef PLAYER_H
#define PLAYER_H

#include "Position.h"
#include "Game_Object.h"

class Player : public Game_Object
{
public:
	Player(int row, int col, char symbol);
	Player() = default;

	/**
	Returns if the player is alive or dead
	@return true if is alive, false otherwise
	*/
	bool isAlive() const;

	/**
	Sets the player as dead
	@return (none)
	*/
	void setAsDead();

private:

	bool alive;

};
#endif
