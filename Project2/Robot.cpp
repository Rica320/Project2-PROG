#include "Robot.h"

int Robot::robotCounter = 0;
Robot::Robot(int row, int col)
{
	this->row = row;
	this->col = col;
	id = ++robotCounter;
	alive = true;
}

inline int Robot::getID() const
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

inline int Robot::getRow() const
{
	return row;
}

inline int Robot::getCol() const
{
	return col;
}

inline Position Robot::getPosition() const
{
	return { row, col };
}

inline bool Robot::isAlive() const
{
	return alive;
}

inline void Robot::setRow(int x) {
	row = x;
}

inline void Robot::setCol(int x) {
	col = x;
}

inline void Robot::setPosition(const Position& pos) {
	row = pos.row;
	col = pos.col;
}

inline void Robot::setAsDead() {
	alive = false;
}

