#include "Post.h"
Post::Post(int row, int col, char type) {
	this->row = row;
	this->col = col;
	this->type = type;
}

int Post::getRow() const {
	return row;
}

int Post::getCol() const {
	return col;
}

char Post::getSymbol() const {
	return type;
}

bool Post::isElectrified() const {
	return type == '*';
}

bool Post::isExit() const {
	return type == 'O';
}