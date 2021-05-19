#ifndef PLAYER_H
#define PLAYER_H

#include "Position.h"

class Player
{
public:
	Player(int row, int col, char symbol);
	Player() = default;
	int getRow() const;
	int getCol() const;
	char getSymbol() const;
	bool isAlive() const;
	void setAsDead();
	void move(Movement delta); // why bool??
private:
	int row, col;
	bool alive;
	char symbol;
};
#endif
