// T04_G07

#ifndef MAZE_H
#define MAZE_H

#include "Position.h"
#include "Post.h"

#include <map>

class Maze {
public:
	
	/**
	Creates maze object.
	*/
	Maze(int numRows, int numCols);

	Maze() = default; 

	/**
	Gets posts.
	@return posts on the maze
	*/
	const std::map<Position, Post>& getPosts() const;

	/**
	Gets posts.
	@return posts on the maze
	*/
	std::map<Position, Post>& getPosts();// Not const cus' of the possibility of override from robots 

	/**
	Adds post in a certain position to the maze posts.
	@param post - the new post
	@param position - the new post's position
	@return (none)
	*/
	void addPost(const Post& post, const Position& position);

	/**
	Gets number of rows in the maze.
	@return number of rows
	*/
	int getnumRows() const;

	/**
	Gets number of columns in the maze.
	@return number of columns
	*/
	int getnumCols() const;

private:
	int numRows{}, numCols{};
	std::map<Position, Post> posts;
};

#endif