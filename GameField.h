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
//допустимые конструкторы и деструктор
public:
	//конструктор, принимающий только количество клеток стороны "поля"
	explicit GameField(unsigned sideSize, const StatusVector& stVec = StatusVector(1))						// пользовательский размер поля
		: mSize(sideSize), fieldStatusVec(stVec)
	{
		if (sideSize < 5)
		{
			std::cerr << "\nРазмер поля меньше минимально допустимого (5)";
			this->~GameField();
		}
		srand(static_cast<unsigned>(time(0)));
		rand();
		pField = setGameField();
	}

	GameField(const StatusVector& stVec = StatusVector(1))													// один из стандартных размеров поля
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
// функции внешнего доступа
public:
	const unsigned getSize() const { return mSize; };
	void printGameField();															// выводит текущий вид игрового поля
	void changeCell(const Point& pnt, const std::string& newStatus);				// поменять заполнение отдельной ячейки
	void redrawField(const StatusVector& pointVec);									// заполнить поле проходами, стенами и прочим
	const std::string getCellStatus(const Point& pnt) const;						// узнать текущее заполнение клетки
	void pointToPointAlg(const Point& entrancePnt, const Point& exitPnt, const std::string& newStatus);


	bool currentFieldCell(const Point& pnt) const;												// принадлежит ли выбранная точка полю


	//пласт функций для проверок возможности передвижения и помощи другим функциям в вопросах перемещения объектов
	const unsigned short CanToPoint(const Point& pnt) const;									// возвращает только количество находящихся рядом клеток поля
	const unsigned short CanToPoint(const Point& pnt, std::vector<Point>& listRef);				// как прошлая, плюс модифицирует вектор 
	const unsigned short getFreePointNum() const;												// количество оставшихся клеток "  "

	const size_t getPointSomeCells(std::list<Point>& pointList, unsigned short typeCells = 0);	// заполняет контейнер координатами всех ячеек выбранного типа, ...
	// возвращает количество таких клеток

	bool canToAdjacentMove(const Point& pnt) const;												// можно ли встать на клетку с соседних (является ли она "__")

	void changeSomeCells(unsigned short typeCells, unsigned short newType) ;					// заменить все ячейки одного типа ячейками другого
	void removeDeadEnds(unsigned short variant);												// удалить тупики (установить другой выбранный тип вместо них)
	void removeUnnecessaryCells(const Point& entrancePnt, const Point& exitPnt);				// заполнить стенами свободные клетки поля, не необходимые для прохождения
	void redrawFieldWithDE(const StatusVector& pointVec);										// перерисовать поле с 2 дополнительными случайными тупиками
	void printKeyPoints() const;																// вывести в командную строку все ключевые точки с пояснениями


	const Point& getKeyPoint(unsigned short index) const;										// для получения ключевой точки



//данные-члены и функции внутреннего доступа
private:

	GameField(const GameField&);
	const GameField& operator= (const GameField&);

	unsigned mSize;												// размер стороны поля
	std::string** pField;										// указатель на поле
	std::string** setGameField();								// генерация поля
	void removeGameField();										// освобождение динамической памяти поля (для деструктора)
	void setSideSize();											// установка одного из размеров поля по умолчанию, выбранного случайным образом (5х5, 10х10, 15х15 или 20х20)
	const StatusVector fieldStatusVec;
	std::vector<Point> vecKeyFieldPoint;						// Важные точки поля (вход, выход, тупики, и т.д.)
};

