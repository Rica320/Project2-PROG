// T04_G07

#include "Maze.h"

//------------------------------------------------------------------------
Maze::Maze(int numRows, int numCols) {
	this->numRows = numRows;
	this->numCols = numCols;
}

//------------------------------------------------------------------------
void Maze::addPost(const Post& post, const Position& position) {
	std::pair<Position, Post> pair;
	pair = std::make_pair(position,post);
	posts.insert(pair);
}

//------------------------------------------------------------------------
int Maze::getnumRows() const {
	return numRows;
}

//------------------------------------------------------------------------
int Maze::getnumCols() const {
	return numCols;
}

//------------------------------------------------------------------------
const std::map<Position, Post>& Maze::getPosts() const{
	return posts;
}

//------------------------------------------------------------------------
std::map<Position, Post>& Maze::getPosts() {
	return posts;
}