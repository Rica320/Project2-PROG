#include "Robot.h"

int Robot::robotCounter = 0;

//------------------------------------------------------------------------
Robot::Robot(int row, int col, char symbol)
        : Game_Object(row,col,symbol)
{
	id = ++robotCounter;
	if (symbol == aliveRobot)
		alive = true;
	else 
		alive = false;
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
