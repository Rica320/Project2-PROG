#ifndef ROBOT_H
#define ROBOT_H

#include "Position.h"

class Robot {
public:
	// enum State { ALIVE, STUCK, DEAD }; bool alive -> ??
	Robot(int row, int col);
	Robot() = default;
	/*~Robot();*/
	int getID() const;
	char getSymbol() const; // get char representation of robot (R if alive, r if dead)
	int getRow() const;
	int getCol() const;
	Position getPosition() const;
	bool isAlive() const;
	void setRow(int x);
	void setCol(int y);
	void setPosition(const Position& pos);
	void setAsDead();
	void move(Movement delta); // why bool??
	static int getRobotCounter() { return robotCounter; };
	static void resetRobotCounter() { robotCounter = 0; };
	
	//other methods - maybe a move function
private:
	static int robotCounter; //used to attribute automatically the id to the robots - USE THIS AFTER FOR THE OVERLOAD <
	int id;
	int row, col;
	bool alive;
	// other attributes (?)
};


#endif

