// T04_G07

#include "Player.h"

//------------------------------------------------------------------------
Player::Player(int row, int col, char symbol) : Game_Object(row,col,symbol)
{
	if (symbol == alivePlayer)
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
	symbol = deadPlayer;
	alive = false;
}
