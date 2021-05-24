#include "Maze.h"

Maze::Maze(int numRows, int numCols) {
	this->numRows = numRows;
	this->numCols = numCols;
	 
}

bool Maze::addPost(const Post& post, const Position& position) {
	std::pair<std::map<Position, Post>::iterator, bool> iter;
	iter = posts.insert(std::pair<Position, Post>(position, post));

	if (!iter.second) {
		return false; // DEBUG ONLY
	}
	return true;

}

int Maze::getnumRows() const {
	return numRows;
}

int Maze::getnumCols() const {
	return numCols;
}

const std::map<Position, Post>& Maze::getPosts() const{
	return posts;
}
//
//std::map<Position, Post>& Maze::getPosts() {
//	return posts;
//}