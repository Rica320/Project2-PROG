#include "Robot.h"

int Robot::robotCounter = 0;
Robot::Robot(int row, int col)
{
	this->row = row;
	this->col = col;
	id = ++robotCounter;
	alive = true;
}

int Robot::getID() const
{
	return id;
}


char Robot::getSymbol() const
{
	// get char representation of robot (R if alive, r if dead)
	if (alive)
		return 'R';
	return 'r';
}

int Robot::getRow() const
{
	return row;
}

int Robot::getCol() const
{
	return col;
}

Position Robot::getPosition() const
{
	return { row, col };
}

bool Robot::isAlive() const
{
	return alive;
}

void Robot::setRow(int x) {
	row = x;
}

void Robot::setCol(int x) {
	col = x;
}

void Robot::setPosition(const Position& pos) {
	row = pos.row;
	col = pos.col;
}

void Robot::setAsDead() {
	alive = false;
}

void Robot::move(Movement delta) {
	row += delta.dRow;
	col += delta.dCol;
}