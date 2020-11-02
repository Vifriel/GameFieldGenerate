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
			std::cerr << "Некорректный индекс конструктора StatusVector";
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

	void fillCellStatusVector();
	/*	0 - "  "					- проходимая точка
	*	1 - "@@"					- стена
	* 	2 - "[\"					- вход на уровень
	*	3 - "/]"					- выход с уровня
	*	4 - "CP"					- контрольная точка (для прочих функций)
	*	5 - "DE"					- тупик для пути (dead end). Нужен для последующего превращения в стену, если путь в итоге был найден даже с ним.
	*	6 - "_?"					- неинициализированная точка
	*/	

	void fillObjectDesignationVector();
};

