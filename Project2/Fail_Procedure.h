#ifndef FAIL_PROCEDURE
#define FAIL_PROCEDURE

#include <iostream>
#include <limits>

/**
Deals with invalid inputs, clearing the buffer or exiting the program if necessary
@return (none)
*/
void isInvalid();

/**
Deals with input Ctrl-Z/D, exiting the program
@return (none)
*/
void isExit();

#endif