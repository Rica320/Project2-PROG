// T04_G07.cpp
// Project2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Game.h"
#include "Menu.h"

int main()
{
	Menu menu;

    menu.showIntro();
    menu.menuLoop();

	return 0;
}
