#ifndef POSITION_H
#define POSITION_H

#include <tuple>

///////////////////////////////////////////////////////////////////////////////
struct Movement
{
	int dRow, dCol; // displacement, taking into account the chosen movement
};
///////////////////////////////////////////////////////////////////////////////
struct Position
{
	int row, col;
};
inline bool operator <(const Position& left, const Position& right)
	{
        if(left.row != right.row)
            return  left.row < right.row;
		return left.col < right.col;

	}
inline bool operator ==(const Position& left, const Position& right)
{
	return left.row == right.row && left.col ==right.col;
}

inline Position operator +(const Position& left, const Movement& right)
{
    return {left.row + right.dRow , left.col + right.dCol};
}
inline Position operator +(const Movement& left, const Position& right)
{
    return {right.row + left.dRow , right.col + left.dCol};
}

#endif // !POSITION_H
