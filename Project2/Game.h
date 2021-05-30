#ifndef GAME_H
#define GAME_H

// classes
#include "Position.h"
#include "Robot.h"
#include "Player.h"
#include "Post.h"
#include "Maze.h"
#include "Fail_Procedure.h"

// stl headers
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
	
	/**
	Opens the maze file and creats a maze object and objects for the chars in
	the file (posts, robots and player).
	@param filename - the name of the maze file
	*/
	explicit Game(const std::string& filename);
	
	/**
	Handles the game while the user is playing.
	@return true if player wins, otherwise false
	*/
	bool play();

private:
	
	/**
	Displays the game.
	@return (none)
	*/
	void showGameDisplay() const;
	
	/**
	Checks if player and robot collided, setting player as dead if they did.
	@param robot - the robot
	@return true if they collided, false otherwise
	*/
	bool collidePlayer(Robot& robot);

	/**
	Template function to check if robots or player collided with posts.
	@param aObj - robot or player
	@return if post is electrified for robots, and win/lose for player
	*/
	template<typename T>
	bool collidePosts(T& aObj); // DO a template with this

	/**
	Checks if each robot collided with other robots.
	@param robot - the robot
	@return true if they collided, false otherwise
	*/
	void collideRobots(Robot& robot);

	/**
	Returns char in a position
	@param apos - position
	@return char (H,h,R,r,*,+,O, )
	*/
	char inPosRobot(Position apos) const;

	/**
	Asks the user about the move until getting a valid key
	(moving key to a place without (r) or (+) or leave (see isInvalid) ).
	@return the key chosen (Q, W, E, A, S, D, Z, X, C)
	*/
	char getMove() const;
	
	/**
	Moves each alive robot and handles the consequences of the move
	@param robot - the robot
	@return true if they collided, false otherwise
	*/
	void moveRobots();
	
	/**
	Asks the user about the move until getting a valid key
	(moving key to a place without (r) or (+) or leave (see isInvalid) ).
	@return the key chosen (Q, W, E, A, S, D, Z, X, C)
	*/
	bool validMove(char c) const;
	
	/**
	Gives the displacement based on the key chosen.
	@param c - the key chosen (Q, W, E, A, S, D, Z, X, C)
	@return displacement in a movement struct
	*/
	static Movement ctom(char c) ;

private:

	Maze maze;
	Player player{};
	std::vector<Robot> robots;

};

template<typename T>
bool Game::collidePosts(T& aObj) {

	std::map<Position, Post>& posts = maze.getPosts();
	if (posts.find(aObj.getPosition()) != posts.end()) {
		if (typeid(T) == typeid(Robot)) {
			aObj.setAsDead();
			return posts.find(aObj.getPosition())->second.isElectrified();
		}
		else if(typeid(T) == typeid(Player))
		{
			bool b = posts.find(aObj.getPosition())->second.isExit();
			if (!b)
				aObj.setAsDead();
			return true; // a collision occurred, the result (win/lose) is in the player
		}
	}
	return false;
}

#endif