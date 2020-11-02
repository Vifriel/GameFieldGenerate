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
	/*	0 - Invalide			- ������ ����� ��������� �� ��������� �������� ���� ��� �����������
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
	/*	0 - "  "					- ���������� �����
	*	1 - "@@"					- �����
	*	2 - "[\"					- ���� �� �������
	*	3 - "/]"					- ����� � ������
	*	4 - "CP"					- ����������� ����� (��� ������ �������)
	*	5 - "DE"					- ����� ��� ���� (dead end). ����� ��� ������������ ����������� � �����, ���� ���� � ����� ��� ������ ���� � ���.
	*	6 - "_?"					- �������������������� �����
	*	7 - "TV"					- �������� ���������� ������������� �����
	*	8 - "CC"					- ����������� ����������� �����
	*/
}

void fillObjectDesignationVector()
{

}
