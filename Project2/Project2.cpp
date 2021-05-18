// T04_G07.cpp
// Project2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
/*
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <cctype>
#include <ctime>
*/

#include "Header1.h"

using namespace std;

Player::Player(int row, int col, char symbol)
{
	this->row = row;
	this->col = col;
	this->symbol = symbol;
}

int Player::getRow() const
{
	return row;
}

int Player::getCol() const
{
	return col;
}

char Player::getSymbol() const
{
	return symbol;
}

bool Player::isAlive() const
{
	if (getSymbol() == 'H')
		return true;
	return false;
}

void Player::setAsDead()
{
	symbol = 'h';
}

bool Player::move(Movement delta)
{
	//?
}

int main()
{
	cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
