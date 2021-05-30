// T04_G07

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Position.h"

static const char deadRobot = 'r';
static const char aliveRobot = 'R';
static const char deadHuman = 'h';
static const char aliveHuman = 'H';
static const char elecPost = '*';
static const char nonElecPost = '+';
static const char exitGate = 'O';

class Game_Object {
public:
    
    /**
    Creates a object for the robot, the player or the post with its attributes.
    @param row - row of the object
    @param col - column of the object
    @param symbol - state of the object (alive/dead for player and robot, eletrified/not for posts)
    */
    Game_Object(int row, int col, char symbol) :row{row},col{col},symbol{symbol}{};
    Game_Object() = default;

    /**
    Gets object symbol (lower case for dead, or upper case for alive).
    @return char for robot or player state
    */
    char getSymbol() const;

    /**
    Gets object row number.
    @return row of the object
    */
    int getRow() const;

    /**
    Gets object column number.
    @return column of the object
    */
    int getCol() const;

    /**
    Gets object position.
    @return position of the object
    */
    Position getPosition() const;

    /**
    Updates object position.
    @param delta - displacement
    @return (none)
    */
    void move(Movement delta);

protected:
    char symbol;
    int row, col;

};


#endif //GAME_OBJECT_H