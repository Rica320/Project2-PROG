// T04_G07

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Position.h"

class Game_Object {
public:
    
    /**
    Creates a object for the Game
    @param row - row of the object
    @param col - column of the object
    @param symbol - state of the object (alive/dead for player and robot, eletrified/not for posts)
    */
    Game_Object(int row, int col, char symbol) :row{row},col{col},symbol{symbol}{};
    Game_Object() = default;

    /**
    Gets object symbol (lower case if dead, or upper case if alive).
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