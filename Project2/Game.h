#ifndef GAME_H
#define GAME_H

#include "Position.h"
#include "Robot.h"
#include "Player.h"
#include "Post.h"
#include "Maze.h"

#include <cctype>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <iostream>

class Game {
public:
	explicit Game(const std::string& filename);
	// This constructor should initialize the Maze, the vector of Robots, and the Player,
	// using the chars read from the file
	bool play(); // implements the game loop; returns true if player wins, false otherwise
	bool isValid(); //????remove????
private:
	void showGameDisplay() const;
	//bool addRobot(const Position& apos, Robot& aRobot);
	// bool collidePlayer(Robot& aObj, Post& post); // check if aObj collided with post (and possibly set it as dead) returns true if the post is electrified
	bool collidePlayer(Robot& robot); // check if human and aObj collided (and possibly set human as dead)
	// bool collidePlayer(Player& player, Post& post);
	template<typename T>
	bool collidePosts(T& robot); // DO a template with this 
	void collideRobots(Robot& robot);
	char inPos(Position apos) const;
	char getMove() const;
	void moveRobots();
	bool validMove(char c) const;
	static Movement ctom(char c) ;

	// other methods, for example:
	// to check if player is trying to move to a valid place
	// to apply a valid playGame and check collisions
	// to check if two robots collidePlayer (and possibly set them as dead)
	// etc.
private:
	Maze maze;
	Player player{};
	std::vector<Robot> robots;
	int aliveRobots;
	//std::map<Position, Robot&> RobotsMap;
	//other attributes
	// MAP POSITION WITH POSTS??
	// MAP POSITION WITH ROBOTS??
};

template<typename T>
bool Game::collidePosts(T& aObj) {

	std::map<Position, Post>& posts = maze.getPosts();
	if (posts.find(aObj.getPosition()) != posts.end()) { // maybe is not necessary the if
		if (typeid(T) == typeid(Robot)) {
			aObj.setAsDead();
			aliveRobots--;
			return posts.find(aObj.getPosition())->second.isElectrified();
		}
		else if(typeid(T) == typeid(Player))
		{
			bool b = posts.find(aObj.getPosition())->second.isExit();
			if (!b)
				aObj.setAsDead();
			return true; // a collision occurred, the result (win/loose) is in the player
		}
	}
	return NULL; 
}


#endif