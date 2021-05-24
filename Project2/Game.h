#ifndef GAME_H
#define GAME_H

#include "Position.h"
#include "Robot.h"
#include "Player.h"
#include "Post.h"
#include "Maze.h"
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <iostream>

class Game {
public:
	Game(const std::string& filename);
	// This constructor should initialize the Maze, the vector of Robots, and the Player,
	// using the chars read from the file
	bool play(); // implements the game loop; returns true if player wins, false otherwise
	bool isValid(); //????remove????
private:
	void showGameDisplay() const;
	//bool addRobot(const Position& apos, Robot& aRobot);
	bool collide(Robot& robot, Post& post); // check if robot collided with post (and possibly set it as dead) returns true if the post is electrified
	bool collide(Robot& robot, Player& player); // check if human and robot collided (and possibly set human as dead)
	bool collide(Player& player, Post& post);
	char getMove() const;
	bool moveRobots(); // return true if they all are dead or the player is dead
	bool validMove(char c) const;
	Movement ctom(char c) const;
	// other methods, for example:
	// to check if player is trying to move to a valid place
	// to apply a valid playGame and check collisions
	// to check if two robots collide (and possibly set them as dead)
	// etc.
private:
	Maze maze;
	Player player;
	std::vector<Robot> robots;
	// alive Robots -> to be used
	//std::map<Position, Robot&> RobotsMap;
	//other attributes
	// MAP POSITION WITH POSTS??
	// MAP POSITION WITH ROBOTS??
};

#endif

