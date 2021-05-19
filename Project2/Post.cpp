#include "Post.h"
Post::Post(int row, int col, char type) {
	this->row = row;
	this->col = col;
	this->type = type;
}

inline int Post::getRow() const {
	return row;
}

inline int Post::getCol() const {
	return col;
}

inline char Post::getSymbol() const {
	return type;
}

bool Post::isElectrified() const {
	if (type == '*')
		return true;
	return false;
}