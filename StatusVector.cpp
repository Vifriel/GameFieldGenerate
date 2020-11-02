#include "StatusVector.h"


const std::string& StatusVector::operator[](const unsigned index) const
{
	return this->stVec[index];
}

void StatusVector::fillPointStatusVector()
{
	this->stVec.clear();
	this->stVec.reserve(10);
	this->stVec.push_back("Invalide");
	this->stVec.push_back("Inner");
	this->stVec.push_back("UpperSide");
	this->stVec.push_back("RightSide");
	this->stVec.push_back("DownSide");
	this->stVec.push_back("LeftSide");
	this->stVec.push_back("UpperLeftCorner");
	this->stVec.push_back("UpperRightCorner");
	this->stVec.push_back("DownRightCorner");
	this->stVec.push_back("DownLeftCorner");
	/*	0 - Invalide			- статус точки находится за пределами текущего поля или неопределен
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
}

void StatusVector::fillCellStatusVector()
{
	this->stVec.clear();
	this->stVec.reserve(9);
	this->stVec.push_back("  ");
	this->stVec.push_back("@@");
	this->stVec.push_back("[\\");
	this->stVec.push_back("/]");
	this->stVec.push_back("CP");
	this->stVec.push_back("DE");
	this->stVec.push_back(" ?");
	this->stVec.push_back("TV");
	this->stVec.push_back("CC");
	/*	0 - "  "					- проходимая точка
	*	1 - "@@"					- стена
	*	2 - "[\"					- вход на уровень
	*	3 - "/]"					- выход с уровня
	*	4 - "CP"					- контрольная точка (для прочих функций)
	*	5 - "DE"					- тупик для пути (dead end). Нужен для последующего превращения в стену, если путь в итоге был найден даже с ним.
	*	6 - "_?"					- неинициализированная точка
	*	7 - "TV"					- временно пройденная неконтрольная точка
	*	8 - "CC"					- проверенная необходимая точка
	*/
}

void fillObjectDesignationVector()
{

}
