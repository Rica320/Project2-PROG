#ifndef ROBOT_H
#define ROBOT_H

#include "Position.h"
#include "Game_Object.h"

class Robot : public Game_Object{
public:
	// enum State { ALIVE, STUCK, DEAD }; bool alive -> ??
	Robot(int row, int col, char symbol);
	Robot() = default;
	int getID() const;
	bool isAlive() const;
	void setAsDead();
	// static int getRobotCounter() { return robotCounter; };
	static void resetRobotCounter() { robotCounter = 0; };

private:
	static int robotCounter; //used to attribute automatically the id to the robots
	int id;
	bool alive;
	// other attributes (?)
};

#endif

