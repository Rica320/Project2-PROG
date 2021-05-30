#ifndef GAME_H
#define GAME_H

// classes
#include "Position.h"
#include "Robot.h"
#include "Player.h"
#include "Post.h"
#include "Maze.h"

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
	the file.
	@param filename - the name of the maze file
	*/
	explicit Game(const std::string& filename);

	// This constructor should initialize the Maze, the vector of Robots, and the Player,
	// using the chars read from the file
	
	/**
	Handles the game while the user is playing.
	@return true if player wins, else false
	*/
	bool play(); // implements the game loop; returns true if player wins, false otherwise
	
	/**
	Deals with invalid inputs, clearing the buffer or exiting the program if necessary
	@return (none)
	*/
	static void isInvalid();

	/**
	Deals with input Ctrl-Z/D, exiting the program
	@return (none)
	*/
	static void isExit();

private:
	
	/**
	Displays the game.
	@return (none)
	*/
	void showGameDisplay() const;
	
	//bool addRobot(const Position& apos, Robot& aRobot);
	// bool collidePlayer(Robot& aObj, Post& post); // check if aObj collided with post (and possibly set it as dead) returns true if the post is electrified
	bool collidePlayer(Robot& robot); // check if human and aObj collided (and possibly set human as dead)
	// bool collidePlayer(Player& player, Post& post);
	template<typename T>
	bool collidePosts(T& aObj); // DO a template with this
	void collideRobots(Robot& robot);
	char inPos(Position apos) const;

	/**
	Asks the user about the move until getting a valid key
	(moving key to a place without (r) or (+) or leave (see isInvalid) ).
	@return the key chosen (Q, W, E, A, S, D, Z, X, C)
	*/
	char getMove() const;
	
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

	// other methods, for example:
	// to check if player is trying to move to a valid place
	// to apply a valid playGame and check collisions
	// to check if two robots collidePlayer (and possibly set them as dead)
	// etc.
private:
	Maze maze;
	Player player{};
	std::vector<Robot> robots;
	//std::map<Position, Robot&> RobotsMap;
	//other attributes
	// MAP POSITION WITH POSTS??
	// MAP POSITION WITH ROBOTS??
};

template<typename T>
bool Game::collidePosts(T& aObj) {

	std::map<Position, Post>& posts = maze.getPosts();
	if (posts.find(aObj.getPosition()) != posts.end()) {
		if (typeid(T) == typeid(Robot)) {
			aObj.setAsDead();
			// aliveRobots--;
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
	return false;
}


#endif