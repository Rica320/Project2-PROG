#include "Player.h"

Player::Player(int row, int col, char symbol)
{
	this->row = row;
	this->col = col;
	this->symbol = symbol;
	alive = true;
}

int Player::getRow() const
{
	return row;
}

int Player::getCol() const
{
	return col;
}

char Player::getSymbol() const
{
	return symbol;
}

bool Player::isAlive() const
{
	return alive;
}

void Player::setAsDead()
{
	symbol = 'h';
	alive = false;
}

void Player::move(Movement delta)
{
	row += delta.dRow;
	col += delta.dCol;
}