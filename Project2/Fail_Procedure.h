// T04_G07

#ifndef FAIL_PROCEDURE
#define FAIL_PROCEDURE

#include <iostream>
#include <limits>

/**
Deals with invalid inputs, clearing the buffer or exiting the program if necessary
Only in the std::cin.
@return (none)
*/
void isInvalid();

/**
Deals with input Ctrl-Z/D, exiting the program
Only in the std::cin.
@return (none)
*/
void isEOF();

#endif