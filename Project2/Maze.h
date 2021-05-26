#ifndef MAZE_H
#define MAZE_H

#include "Position.h"
#include "Post.h"


#include <map>

class Maze {
public:
	Maze(int numRows, int numCols);
	Maze() = default; 
	const std::map<Position, Post>& getPosts() const;
	std::map<Position, Post>& getPosts();// Not const cus' of the possibility of override from robots - see if it is necessary
	bool addPost(const Post& post, const Position& position);
	int getnumRows() const;
	int getnumCols() const;
	// other methods
private:
	int numRows{}, numCols{};
	// data structure that represents the posts
	// vector or maze (await for response)
	std::map<Position, Post> posts;
};

#endif