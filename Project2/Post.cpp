#include "Post.h"

bool Post::isElectrified() const {
	return symbol == '*'; // TODO: IS THIS CONSIDERED A MAGIC NUMBER ???
}

bool Post::isExit() const {
	return symbol == 'O';
}