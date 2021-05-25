// T04_G07.cpp
// Project2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Game.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Robot.h"
#include "Menu.h"

int main()
{
	Menu menu;

	menu.showName();
	menu.askMode();

	return 0;
}
