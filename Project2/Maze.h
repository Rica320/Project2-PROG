#ifndef MAZE_H
#define MAZE_H

#include "Position.h"
#include "Post.h"

class Maze {
public:
	Maze(int numRows, int numCols);
	Maze() = default;
	bool addPost(const Post& post, const Position& position);
	int getnumRows() const;
	int getnumCols() const;
	// other methods
private:
	int numRows, numCols;
	// data structure that represents the posts
	// vector or maze (await for response)
};
#endif