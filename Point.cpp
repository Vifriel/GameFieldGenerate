#include "Point.h"


void Point::changePointStatus()
{
	unsigned short row = this->mRow;
	unsigned short column = this->mColumn;
	unsigned sizeSide = this->fieldSizeSide;

	if (row >= sizeSide || column >= sizeSide)		// (1) если ряд или столбец выходят за пределы поля...
	{
		this->pointStatus = pointStatusVec[0];		// (1) ...статус "точка не принадлежит полю"
	}
	else if ((row > 0 && row < sizeSide - 1) && (column > 0 && column < sizeSide - 1))	// (2) иначе, если точка не находится на границе поля
	{
		this->pointStatus = pointStatusVec[1];		//	(2) ...статус "точка внутри поля"
	}
	else if (row == 0)								// (3) иначе, если точка принадлежит верхнему ряду...
	{
		if (column == 0)							//		(3.1) ... и крайнему левому столбцу...
		{
			this->pointStatus = pointStatusVec[6];	//		(3.1) ... статус "точка левого верхнего угла"
		}
		else if (column == sizeSide - 1)			//		(3.2) ... и крайнему правому столбцу
		{
			this->pointStatus = pointStatusVec[7];	//		(3.2) ... статус "точка правого верхнего угла"
		}
		else
		{
			this->pointStatus = pointStatusVec[2];	//		(3.3) ... статус "точка верхнего ряда"
		}
	}
	else if (row == sizeSide - 1)					//  (4) иначе, если точка принадлежит нижнему ряду...
	{
		if (column == 0)							//		(4.1) ... и крайнему левому столбцу...
		{
			this->pointStatus = pointStatusVec[9];	//		(4.1) ... статус "точка левого нижнего угла"
		}
		else if (column == sizeSide - 1)			//		(4.2) ... и крайнему правому столбцу
		{
			this->pointStatus = pointStatusVec[8];	//		(4.2) ... статус "точка правого нижнего угла"
		}
		else
		{
			this->pointStatus = pointStatusVec[4];	//		(4.3) ... статус "точка нижнего ряда"
		}
	}
	else if (column == 0)							//  (5) иначе, если точка принадлежит крайнему левому столбцу...
	{
		this->pointStatus = pointStatusVec[5];		//	(5) ...соответствующий статус
	}
	else 											//	(6) иначе, если точка принадлежит крайнему правому столбцу...
	{
		this->pointStatus = pointStatusVec[3];		//	(6) ...соответствующий статус 
	}


}

Point& Point::changePoint(int changeRow, int changeColumn)
{
	unsigned short row = this->mRow;
	unsigned short column = this->mColumn;
	
	if (changeRow == 0 && changeColumn == 0)
	{
		row = 0;
		column = 0;
		changePointStatus();
		return *this;
	}
	/*if (((static_cast<int>(row) + changeRow) < 0) || ((static_cast<int>(column) + changeColumn) < 0))
	{
		std::cerr << "\nВыход за нижние границы области (переполнение через разность). Значение не изменено.";
		return *this;
	}*/
	else
	{
		row += changeRow;
		column += changeColumn;
		this->mRow = row;
		this->mColumn = column;
		changePointStatus();
		return *this;
	}
}

const unsigned short Point::distanceTo(const Point& destPoint) const
{
	if (this->getPointStatus() == "Invalide" || destPoint.getPointStatus() == "Invalide")
	{
		std::cerr << "\nОдна из сравниваемых точек (" << this->mRow << "," << this->mColumn << \
			" или " << destPoint.getPointRow() << "," << destPoint.getPointColumn() << ") лежит за пределами поля. Вычисление дистанции бессмысленно.";
		exit(EXIT_FAILURE);
	}

	auto x1 = this->mRow;
	auto y1 = this->mColumn;
	auto x2 = destPoint.getPointRow();
	auto y2 = destPoint.getPointColumn();
	unsigned short xTurn;
	unsigned short yTurn;

	if (x1 >= x2)
		xTurn = x1 - x2;
	else
		xTurn = x2 - x1;

	if (y1 >= y2)
		yTurn = y1 - y2;
	else
		yTurn = y2 - y1;

	return xTurn + yTurn;
}

bool Point::operator== (const Point& p1) const
{
	if (this->getPointRow() == p1.getPointRow() && this->getPointColumn() == p1.getPointColumn())
		return true;
	else return false;
}
bool Point::operator< (const Point& p1) const
{
	auto pRow = this->getPointRow();
	auto p1Row = p1.getPointRow();
	if (pRow != p1Row)
		return pRow < p1Row;
	else
	{
		auto pColumn = this->getPointColumn();
		auto p1Column = p1.getPointColumn();
		return pColumn < p1Column;
	}
}

Point& Point::operator= (const Point& p1)
{
	if (this == &p1)
		return *this;

	this->mRow = p1.getPointRow();
	this->mColumn = p1.getPointColumn();
	this->changePointStatus();
	return *this;
}

Point Point::leftToPoint() const
{
	Point ltpt(*this);
	ltpt.changePoint(0, -1);
	return ltpt;
}

Point Point::upperToPoint() const
{
	Point utpt(*this);
	utpt.changePoint(-1, 0);
	return utpt;
}

Point Point::rightToPoint() const
{
	Point rtpt(*this);
	rtpt.changePoint(0, 1);
	return rtpt;
}

Point Point::downToPoint() const
{
	Point dtpt(*this);
	dtpt.changePoint(1, 0);
	return dtpt;
}

std::ostream& operator<< (std::ostream& out, const Point& point)
{
	out << "\nТочка " << point.getPointRow() << ',' << point.getPointColumn() << " имеет статус " << point.getPointStatus() << " для поля с размером стороны " << \
		point.getFieldSize();
	return out;
}