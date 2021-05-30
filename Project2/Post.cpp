#include "Post.h"

//------------------------------------------------------------------------
bool Post::isElectrified() const {
	return (symbol == elecPost);
}

//------------------------------------------------------------------------
bool Post::isExit() const {
	return (symbol == exitGate);
}