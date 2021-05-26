#include "Maze.h"

Maze::Maze(int numRows, int numCols) {
	this->numRows = numRows;
	this->numCols = numCols;
	 
}

bool Maze::addPost(const Post& post, const Position& position) {
	std::pair<std::map<Position, Post>::iterator, bool> iter;
	std::pair<Position, Post> pair;
	pair = std::make_pair(position,post);
	iter = posts.insert(pair);

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

std::map<Position, Post>& Maze::getPosts() {
	return posts;
}