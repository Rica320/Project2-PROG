#include "Game_Object.h"

//------------------------------------------------------------------------
char Game_Object::getSymbol() const
{
    return symbol;
}

//------------------------------------------------------------------------
int Game_Object::getRow() const
{
    return row;
}

//------------------------------------------------------------------------
int Game_Object::getCol() const
{
    return col;
}

//------------------------------------------------------------------------
Position Game_Object::getPosition() const
{
    return { row, col };
}

//------------------------------------------------------------------------
void Game_Object::move(Movement delta) {
    row += delta.dRow;
    col += delta.dCol;
}