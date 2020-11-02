#pragma once
#include <vector>
#include <iostream>

class StatusVector
{

public:
	StatusVector(unsigned int ownerIndex)
	{
		switch (ownerIndex)
		{
		case 0: fillPointStatusVector(); break;
		case 1: fillCellStatusVector(); break;
		//case 2: fillObjectDesignationVector(); break;
		default:
			std::cerr << "������������ ������ ������������ StatusVector";
			break;
		}
	}
	/*		0 - PointStatus
	*		1 - CellStatus
	*		2 - CellObjectStatus
	*		etc.
	*/

	const std::string&  operator[](const unsigned index) const;
	const size_t getSize() const { return this->stVec.size(); }

private:
	std::vector<std::string> stVec;
	StatusVector& operator= (StatusVector&) {}
	StatusVector() {}

	void fillPointStatusVector();
	/*	0 - Invalide				- ������ ����� ��������� �� ��������� �������� ���� ��� �����������
	*	1 - Inner					- ����� �� ����� �� ����� �� ������ ���� (���������� �����)
	*	2 - UpperSide				- ����� ��������� �� ������� ������� (�� �� � ����)
	*	3 - RightSide				- ����� ��������� �� ������ ������� (�� �� � ����)
	*	4 - DownSide				- ����� ��������� �� ������ ������� (�� �� � ����)
	*	5 - LeftSide				- ����� ��������� �� ����� ������� (�� �� � ����)
	*	6 - UpperLeftCorner			- 6 ... 9 - ����� ��������� � ��������������� �������� ����
	*	7 - UpperRightCorner
	*	8 - DownRightCorner
	*	9 - DownLeftCorner

	*/

	void fillCellStatusVector();
	/*	0 - "  "					- ���������� �����
	*	1 - "@@"					- �����
	* 	2 - "[\"					- ���� �� �������
	*	3 - "/]"					- ����� � ������
	*	4 - "CP"					- ����������� ����� (��� ������ �������)
	*	5 - "DE"					- ����� ��� ���� (dead end). ����� ��� ������������ ����������� � �����, ���� ���� � ����� ��� ������ ���� � ���.
	*	6 - "_?"					- �������������������� �����
	*/	

	void fillObjectDesignationVector();
};

