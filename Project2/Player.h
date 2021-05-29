#ifndef PLAYER_H
#define PLAYER_H

#include "Position.h"
#include "Game_Object.h"

class Player : public Game_Object
{
public:
	Player(int row, int col, char symbol);
	Player() = default;
	bool isAlive() const;
	void setAsDead();
private:
	bool alive;

};
#endif
