#pragma once
#include <iostream>
#include <vector>
#include "StatusVector.h"

class Point
{
public:
	Point(unsigned short row, unsigned short column, const unsigned sizeSide, const StatusVector& stVec = StatusVector(0))
		: mRow(row), mColumn(column), fieldSizeSide(sizeSide), pointStatus("Invalide"), pointStatusVec(stVec)
	{
		changePointStatus();
	}

	explicit Point(unsigned sizeSide, const StatusVector& stVec = StatusVector(0))
		: mRow(0), mColumn(0), fieldSizeSide(sizeSide), pointStatus("UpperLeftCorner"), pointStatusVec(stVec)
	{
		changePointStatus();
	}

public:
	const unsigned short getPointRow() const { return mRow; }
	const unsigned short getPointColumn() const { return mColumn; }
	const unsigned short getFieldSize() const { return fieldSizeSide; }
	const unsigned short distanceTo(const Point& destPoint) const;
	const std::string getPointStatus() const { return pointStatus; }
	Point leftToPoint() const;		// вернуть точку слева,
	Point rightToPoint() const;	// справа,
	Point upperToPoint() const;	// сверху,
	Point downToPoint() const;		// или снизу



	bool operator== (const Point& p1) const;
	Point& operator= (const Point& p1);
	bool operator< (const Point& p1) const;


	Point& changePoint(int changeRow, int changeColumn);
	void changePointStatus();


private:
	unsigned short mRow;
	unsigned short mColumn;
	const unsigned fieldSizeSide;
	std::string pointStatus;
	const StatusVector pointStatusVec;

	void fillStatusVector();
	/*	0 - Invalide				- статус точки находится за пределами текущего поля или неопределен
	*	1 - Inner					- точка не лежит на одной из границ поля (внутренняя точка)
	*	2 - UpperSide				- точка находится на верхней границе (но не в углу)
	*	3 - RightSide				- точка находится на правой границе (но не в углу)
	*	4 - DownSide				- точка находится на нижней границе (но не в углу)
	*	5 - LeftSide				- точка находится на левой границе (но не в углу)
	*	6 - UpperLeftCorner			- 6 ... 9 - точка находится в соответствующем названию углу
	*	7 - UpperRightCorner
	*	8 - DownRightCorner
	*	9 - DownLeftCorner
	
	*/
};

 //перегруженные операторы для класса
std::ostream& operator<< (std::ostream& out, const Point& point);

