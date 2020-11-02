#include "Point.h"


void Point::changePointStatus()
{
	unsigned short row = this->mRow;
	unsigned short column = this->mColumn;
	unsigned sizeSide = this->fieldSizeSide;

	if (row >= sizeSide || column >= sizeSide)		// (1) ���� ��� ��� ������� ������� �� ������� ����...
	{
		this->pointStatus = pointStatusVec[0];		// (1) ...������ "����� �� ����������� ����"
	}
	else if ((row > 0 && row < sizeSide - 1) && (column > 0 && column < sizeSide - 1))	// (2) �����, ���� ����� �� ��������� �� ������� ����
	{
		this->pointStatus = pointStatusVec[1];		//	(2) ...������ "����� ������ ����"
	}
	else if (row == 0)								// (3) �����, ���� ����� ����������� �������� ����...
	{
		if (column == 0)							//		(3.1) ... � �������� ������ �������...
		{
			this->pointStatus = pointStatusVec[6];	//		(3.1) ... ������ "����� ������ �������� ����"
		}
		else if (column == sizeSide - 1)			//		(3.2) ... � �������� ������� �������
		{
			this->pointStatus = pointStatusVec[7];	//		(3.2) ... ������ "����� ������� �������� ����"
		}
		else
		{
			this->pointStatus = pointStatusVec[2];	//		(3.3) ... ������ "����� �������� ����"
		}
	}
	else if (row == sizeSide - 1)					//  (4) �����, ���� ����� ����������� ������� ����...
	{
		if (column == 0)							//		(4.1) ... � �������� ������ �������...
		{
			this->pointStatus = pointStatusVec[9];	//		(4.1) ... ������ "����� ������ ������� ����"
		}
		else if (column == sizeSide - 1)			//		(4.2) ... � �������� ������� �������
		{
			this->pointStatus = pointStatusVec[8];	//		(4.2) ... ������ "����� ������� ������� ����"
		}
		else
		{
			this->pointStatus = pointStatusVec[4];	//		(4.3) ... ������ "����� ������� ����"
		}
	}
	else if (column == 0)							//  (5) �����, ���� ����� ����������� �������� ������ �������...
	{
		this->pointStatus = pointStatusVec[5];		//	(5) ...��������������� ������
	}
	else 											//	(6) �����, ���� ����� ����������� �������� ������� �������...
	{
		this->pointStatus = pointStatusVec[3];		//	(6) ...��������������� ������ 
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
		std::cerr << "\n����� �� ������ ������� ������� (������������ ����� ��������). �������� �� ��������.";
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
		std::cerr << "\n���� �� ������������ ����� (" << this->mRow << "," << this->mColumn << \
			" ��� " << destPoint.getPointRow() << "," << destPoint.getPointColumn() << ") ����� �� ��������� ����. ���������� ��������� ������������.";
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
	out << "\n����� " << point.getPointRow() << ',' << point.getPointColumn() << " ����� ������ " << point.getPointStatus() << " ��� ���� � �������� ������� " << \
		point.getFieldSize();
	return out;
}