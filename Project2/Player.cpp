#include "Player.h"

//------------------------------------------------------------------------
Player::Player(int row, int col, char symbol) : Game_Object(row,col,symbol)
{
	if (symbol == aliveHuman)
	    alive = true;
	else
	    alive = false;
}

//------------------------------------------------------------------------
bool Player::isAlive() const
{
	return alive;
}

//------------------------------------------------------------------------
void Player::setAsDead()
{
	symbol = deadHuman;
	alive = false;
}
