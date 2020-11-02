#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <list>
#include <cassert>

#include "Point.h"
#include "StatusVector.h"

class GameField
{
//���������� ������������ � ����������
public:
	//�����������, ����������� ������ ���������� ������ ������� "����"
	explicit GameField(unsigned sideSize, const StatusVector& stVec = StatusVector(1))						// ���������������� ������ ����
		: mSize(sideSize), fieldStatusVec(stVec)
	{
		if (sideSize < 5)
		{
			std::cerr << "\n������ ���� ������ ���������� ����������� (5)";
			this->~GameField();
		}
		srand(static_cast<unsigned>(time(0)));
		rand();
		pField = setGameField();
	}

	GameField(const StatusVector& stVec = StatusVector(1))													// ���� �� ����������� �������� ����
		:fieldStatusVec(stVec)
	{
		srand(static_cast<unsigned>(time(0)));
		rand();
		setSideSize();
		pField = setGameField();
	}



	~GameField()
	{
		removeGameField();
	}
// ������� �������� �������
public:
	const unsigned getSize() const { return mSize; };
	void printGameField();															// ������� ������� ��� �������� ����
	void changeCell(const Point& pnt, const std::string& newStatus);				// �������� ���������� ��������� ������
	void redrawField(const StatusVector& pointVec);									// ��������� ���� ���������, ������� � ������
	const std::string getCellStatus(const Point& pnt) const;						// ������ ������� ���������� ������
	void pointToPointAlg(const Point& entrancePnt, const Point& exitPnt, const std::string& newStatus);


	bool currentFieldCell(const Point& pnt) const;												// ����������� �� ��������� ����� ����


	//����� ������� ��� �������� ����������� ������������ � ������ ������ �������� � �������� ����������� ��������
	const unsigned short CanToPoint(const Point& pnt) const;									// ���������� ������ ���������� ����������� ����� ������ ����
	const unsigned short CanToPoint(const Point& pnt, std::vector<Point>& listRef);				// ��� �������, ���� ������������ ������ 
	const unsigned short getFreePointNum() const;												// ���������� ���������� ������ "  "

	const size_t getPointSomeCells(std::list<Point>& pointList, unsigned short typeCells = 0);	// ��������� ��������� ������������ ���� ����� ���������� ����, ...
	// ���������� ���������� ����� ������

	bool canToAdjacentMove(const Point& pnt) const;												// ����� �� ������ �� ������ � �������� (�������� �� ��� "__")

	void changeSomeCells(unsigned short typeCells, unsigned short newType) ;					// �������� ��� ������ ������ ���� �������� �������
	void removeDeadEnds(unsigned short variant);												// ������� ������ (���������� ������ ��������� ��� ������ ���)
	void removeUnnecessaryCells(const Point& entrancePnt, const Point& exitPnt);				// ��������� ������� ��������� ������ ����, �� ����������� ��� �����������
	void redrawFieldWithDE(const StatusVector& pointVec);										// ������������ ���� � 2 ��������������� ���������� ��������
	void printKeyPoints() const;																// ������� � ��������� ������ ��� �������� ����� � �����������


	const Point& getKeyPoint(unsigned short index) const;										// ��� ��������� �������� �����



//������-����� � ������� ����������� �������
private:

	GameField(const GameField&);
	const GameField& operator= (const GameField&);

	unsigned mSize;												// ������ ������� ����
	std::string** pField;										// ��������� �� ����
	std::string** setGameField();								// ��������� ����
	void removeGameField();										// ������������ ������������ ������ ���� (��� �����������)
	void setSideSize();											// ��������� ������ �� �������� ���� �� ���������, ���������� ��������� ������� (5�5, 10�10, 15�15 ��� 20�20)
	const StatusVector fieldStatusVec;
	std::vector<Point> vecKeyFieldPoint;						// ������ ����� ���� (����, �����, ������, � �.�.)
};

