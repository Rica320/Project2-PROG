#ifndef ROBOT_H
#define ROBOT_H

#include "Position.h"
#include "Game_Object.h"

class Robot : public Game_Object{
public:

	/**
	Creates a robot object with its id.
	*/
	Robot(int row, int col, char symbol);
	Robot() = default;

	/**
	Returns the id of the robot.
	@return robot's id
	*/
	int getID() const;

	/**
	Checks if the robot is alive.
	@return true if alive, otherwise dead
	*/
	bool isAlive() const;

	/**
	Sets the robot as dead.
	@return (none)
	*/
	void setAsDead();

	// static int getRobotCounter() { return robotCounter; };
	static void resetRobotCounter() { robotCounter = 0; };

private:

	static int robotCounter; //used to attribute automatically the id to the robots
	int id;
	bool alive;

};

#endif

