//
// Created by ricar on 29/05/2021.
//

#ifndef PROJECT2_GAME_OBJECT_H
#define PROJECT2_GAME_OBJECT_H

#include "Position.h"

class Game_Object {
public:
    Game_Object(int row, int col, char symbol) :row{row},col{col},symbol{symbol}{};
    Game_Object() = default;
    char getSymbol() const;
    int getRow() const;
    int getCol() const;
    Position getPosition() const;
    void move(Movement delta);
protected:
    char symbol;
    int row, col;

};


#endif //PROJECT2_GAME_OBJECT_H
