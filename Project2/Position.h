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
		return std::tie(left.row, left.col) < std::tie(right.row,right.col);

	}

#endif // !POSITION_H
