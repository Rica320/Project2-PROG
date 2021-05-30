#include "Post.h"

//------------------------------------------------------------------------
bool Post::isElectrified() const {
	return (symbol == '*');
}

//------------------------------------------------------------------------
bool Post::isExit() const {
	return (symbol == 'O');
}