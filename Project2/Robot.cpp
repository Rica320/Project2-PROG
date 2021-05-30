#include "Robot.h"

int Robot::robotCounter = 0;

//------------------------------------------------------------------------
Robot::Robot(int row, int col, char symbol)
        : Game_Object(row,col,symbol)
{
	id = ++robotCounter;
	alive = true;
}

//------------------------------------------------------------------------
int Robot::getID() const
{
	return id;
}

//------------------------------------------------------------------------
bool Robot::isAlive() const
{
	return alive;
}

//------------------------------------------------------------------------
void Robot::setAsDead() {
	alive = false;
	symbol = deadRobot;
}
