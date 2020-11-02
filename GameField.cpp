#include "GameField.h"


std::string** GameField::setGameField()
{
	// ������ ���������� �� ��������� (���������� ������)
	std::string** rows = new std::string * [this->mSize];
	// ������� ���������� �� ������ ������ ����������� �������
	for (size_t i = 0; i < this->mSize; i++)
	{
		rows[i] = new std::string[this->mSize];
		for (size_t j = 0; j < this->mSize; j++)
		{
			rows[i][j] = this->fieldStatusVec[6];	// " ?"
		}
	}
	return rows;
}

void GameField::printGameField()
{
	std::cout << "\n";
	auto ptr = this->pField;
	for (size_t i = 0; i < this->mSize; i++)
	{
		for (size_t j = 0; j < this->mSize; j++)
		{
			std::cout << ptr[i][j];
		}
		std::cout << "\n";
	}
}

void GameField::removeGameField()
{
	if (this->pField != nullptr)
	{
		for (size_t i = 0; i < this->mSize; i++)
		{
			delete[] this->pField[i];
		}
		delete[] this->pField;

		pField = nullptr;
	}
}

void GameField::setSideSize()
{
	unsigned short i = ((rand() % 4) + 1) * 5;
	this->mSize = i;
}

const std::string GameField::getCellStatus(const Point& pnt) const
{
	if (pnt.getPointRow() >= this->mSize || pnt.getPointColumn() >= this->mSize)
	{
		std::cerr << "\n����� ��������� �� ��������� ����.";
		exit(EXIT_FAILURE);
	}
	return this->pField[pnt.getPointRow()][pnt.getPointColumn()];
}


void GameField::changeCell(const Point& pnt, const std::string& newStatus)
{
	const unsigned short row = pnt.getPointRow();
	const unsigned short column = pnt.getPointColumn();
	const std::string status = pnt.getPointStatus();
	if (status == "Invalide")
	{
		std::cerr << "����� � ������������ " << row << " , " << column << " ��������� �� ��������� ����.";
		return;
	}
	else if (this->pField[row][column] == newStatus)
	{
		return;
	}
	else
	{
		this->pField[row][column] = newStatus;
	}
}

void GameField::redrawField(const StatusVector& pointVec)
{
	for (size_t i = 0; i < this->mSize; i++)
	{
		for (size_t j = 0; j < this->mSize; j++)
		{
			this->pField[i][j] = this->fieldStatusVec[6];	// " ?"
		}
	}

	auto fieldSize = getSize();
	auto pointStatusVec = pointVec;
	const StatusVector& cellStatusVec = this->fieldStatusVec;
	unsigned short x;
	unsigned short y;

	x = rand() % fieldSize;
	y = rand() % fieldSize;

	Point pointOfEntry(x, y, fieldSize, pointVec);				// ���������������� ����� �����
	unsigned short minDistance = fieldSize -1;					// ��������� ���������� ����������� ��������� ����� ������ ����� � ������. �� ������, ���� ������ � ��������.

	if (!(fieldSize % 2))
		minDistance--;											// ���� ������� ���� ������, ����������� ��������� �� 1 ������ (��� �������, ����� ���� � ������ � ���� 2 ������)


	do
	{
		x = rand() % fieldSize;
		y = rand() % fieldSize;
	} while (pointOfEntry.distanceTo(Point(x, y, fieldSize, pointVec)) < minDistance);

	Point exitPoint(x, y, fieldSize, pointVec);

	changeCell(pointOfEntry, cellStatusVec[2]);
	changeCell(exitPoint, cellStatusVec[3]);

	pointToPointAlg(pointOfEntry, exitPoint, cellStatusVec[0]);
	//changeSomeCells(6, 0);
	//printGameField();
	removeUnnecessaryCells(pointOfEntry, exitPoint);


	//unsigned short minDistToDeadEnd = ;
	
/*	for (unsigned i = 0; i < fieldSize; i++)
	{
		for (unsigned j = 0; j < fieldSize; j++)
		{
			if (getCellStatus(Point(i, j, fieldSize, pointStatusVec)) == this->fieldStatusVec[6]) // fieldStatusVec[6] == "_?"
			{
				auto choise = rand() % 3;
				if (choise == 1)
				{
					changeCell(Point(i, j, fieldSize, pointStatusVec), cellStatusVec[1]);
				}
				else if (choise == 0)
				{
					changeCell(Point(i, j, fieldSize, pointStatusVec), cellStatusVec[0]);
				}
			}
		}
	}*/
}

bool GameField::currentFieldCell(const Point& pnt) const
{
	if (pnt.getPointRow() >= this->getSize() || pnt.getPointColumn() >= this->getSize())
		return false;
	else
		return true;
}



void GameField::pointToPointAlg(const Point& entrancePnt, const Point& exitPnt, const std::string& newStatus)
{
	std::vector<Point> wayVec; //������ ����� ����
	std::vector<Point> correctForWay; //������, ���������� �� 4 ����������� ���������� ��������

	Point currentPoint = entrancePnt;
	wayVec.push_back(currentPoint);

	// ���� ����� ����
	while (!(currentPoint == exitPnt))
	{
		// std::cout << "\n���������� ��������� � �������� -" << wayVec.size();
		//���� ��������� ��� �������� ����� � �������� ����
		if (this->currentFieldCell(Point(currentPoint).changePoint(-1, 0)))		//������
			correctForWay.push_back(Point(currentPoint).changePoint(-1, 0));
		if (this->currentFieldCell(Point(currentPoint).changePoint(0, 1)))		//������
			correctForWay.push_back(Point(currentPoint).changePoint(0, 1));
		if (this->currentFieldCell(Point(currentPoint).changePoint(1, 0)))		//�����
			correctForWay.push_back(Point(currentPoint).changePoint(1, 0));
		if (this->currentFieldCell(Point(currentPoint).changePoint(0, -1)))		//�����
			correctForWay.push_back(Point(currentPoint).changePoint(0, -1));
		unsigned short direction;
		for (unsigned short i = 0; i < 10; i++)
		{
			direction = rand() % correctForWay.size();
			if (find(wayVec.begin(), wayVec.end(), correctForWay[direction]) == wayVec.end())
			{
				wayVec.push_back(correctForWay[direction]);
				currentPoint = correctForWay[direction];
				break;
			}
			
		}
		currentPoint = correctForWay[direction];
		correctForWay.clear();
	}

	//std::cout << "\n���������� ��������� �� ���������� ��������� �������� -" << wayVec.size();
	for (size_t index = 1; index < wayVec.size() - 1; index++)
	{
		changeCell(wayVec[index], newStatus);
	//	this->printGameField();
	}
	//std::cout << "\n���������� ��������� �� ���������� ����������� ����� -" << wayVec.size();
	return;
}

const unsigned short GameField::CanToPoint(const Point& pnt) const
{
	unsigned short counter = 0;
	if (pnt.upperToPoint().getPointStatus() != "Invalide")
		counter++;
	if (pnt.rightToPoint().getPointStatus() != "Invalide")
		counter++;
	if (pnt.downToPoint().getPointStatus() != "Invalide")
		counter++;
	if (pnt.leftToPoint().getPointStatus() != "Invalide")
		counter++;

	return counter;
}

const unsigned short GameField::CanToPoint(const Point& pnt, std::vector<Point>& listRef)
{
	listRef.clear();
	unsigned short counter = 0;

	Point uPoint(pnt);
	uPoint = pnt.upperToPoint();
	Point rPoint(pnt);
	rPoint = pnt.rightToPoint();
	Point dPoint(pnt);
	dPoint = pnt.downToPoint();
	Point lPoint(pnt);
	lPoint = pnt.leftToPoint();

	if (uPoint.getPointStatus() != "Invalide")
	{
		listRef.push_back(uPoint);
		counter++;
	}
	if (rPoint.getPointStatus() != "Invalide")
	{
		listRef.push_back(rPoint);
		counter++;
	}
	if (dPoint.getPointStatus() != "Invalide")
	{
		listRef.push_back(dPoint);
		counter++;
	}
	if (lPoint.getPointStatus() != "Invalide")
	{
		listRef.push_back(lPoint);
		counter++;
	}
	return counter;
}

const unsigned short GameField::getFreePointNum() const
{
	unsigned short counter = 0;
	auto fieldSize = this->getSize();
	for (unsigned short i = 0; i < fieldSize; i++)
	{
		for (unsigned short j = 0; j < fieldSize; j++)
		{
			if (getCellStatus(Point(i, j, fieldSize)) == "  ")
			{
				counter++;
			}
		}
	}
	return counter;
}

bool GameField::canToAdjacentMove(const Point& pnt) const
{
	if (getCellStatus(pnt) == this->fieldStatusVec[0] || getCellStatus(pnt) == this->fieldStatusVec[3])
		return true;
	else return false;
}

void GameField::changeSomeCells(unsigned short typeCells, unsigned short newType)
{
	if (typeCells >= this->fieldStatusVec.getSize() || newType >= this->fieldStatusVec.getSize())
	{
		std::cerr << "\n� ������� ��������������� ���������� ������ ���� ������� ������������ ������ ��������";
		return;
	}
	auto fieldSize = this->getSize();
	for (unsigned short i = 0; i < fieldSize; i++)
	{
		for (unsigned short j = 0; j < fieldSize; j++)
		{
			Point pnt(i, j, fieldSize);
			if (getCellStatus(pnt) == this->fieldStatusVec[typeCells])
			{
				changeCell(Point(pnt), this->fieldStatusVec[newType]);
			}
		}
	}
}
void GameField::removeDeadEnds(unsigned short variant)
{
	if (variant >= this->fieldStatusVec.getSize())
	{
		std::cerr << "\n� ������� ��������������� ������� ������� ������������ ������ ��������";
		return;
	}
	changeSomeCells(5, variant); // 5 - "DE", dead ends, ������
}

const size_t GameField::getPointSomeCells(std::list<Point>& pointList, unsigned short typeCells)
{
	assert(typeCells < this->fieldStatusVec.getSize() && "\n������� �������� ����� ������ ���� �������� �������� ���� ��� ����������� ���������." );
	pointList.clear();

	for (unsigned short i = 0; i < this->getSize(); i++)
	{
		for (unsigned short j = 0; j < this->getSize(); j++)
		{
			Point pnt(i, j, this->getSize());
			if (getCellStatus(pnt) == this->fieldStatusVec[typeCells])
			{
				pointList.push_back(pnt);
			}
		}
	}

	return pointList.size();
}

void GameField::removeUnnecessaryCells(const Point& entrancePnt, const Point& exitPnt)
{
	std::list<Point> freeCellList;
	size_t counterFCL = getPointSomeCells(freeCellList);
	auto iterFCL = freeCellList.begin();
	Point currentPoint = entrancePnt;
	Point exit = exitPnt;
	std::vector<Point> vecCanToPoint;
	std::vector<Point> vecCanToAdjacentMove;
	std::vector<Point> vecControlPoint;
	std::vector<Point> vecTempValuePoint;
	bool changed{ false };																// ��������� �� ������� �����-�������� �� ���������� � ������ ������� �� �����. ������

	while (counterFCL > 0)
	{
		vecCanToPoint.clear();
		vecCanToAdjacentMove.clear();

		if (currentPoint == exit)														// ���� �� ������� ����� �� ����� �� ������
		{
			changeSomeCells(5, 1);														// ��������������� ��� ������ � �����
			changeSomeCells(0, 1);														// ��� �����, ���������� ����������, � �����
			changeSomeCells(7, 0);														// ��� ��������� ����� � ���������
			changeSomeCells(4, 0);														// ��� ����������� ����� � ���������
			vecTempValuePoint.clear();
			vecControlPoint.clear();
			changed = false;															// ������ ������������ � ������ ������ ���������� �����
			currentPoint = entrancePnt;													// � ������������ ������� �� �����
			//printGameField();
			continue;
		}
		if (getCellStatus(*iterFCL) != this->fieldStatusVec[0] && !changed)								// ���� ������� ����� �� �������� ���������, 
		{
			freeCellList.pop_front();																	// ��������� � ��������� ��������� �����
			iterFCL = freeCellList.begin();
			counterFCL--;
			continue;
		}



			changeCell(*iterFCL, this->fieldStatusVec[1]);									// ������ ������ ��������� ����� �� �����
			unsigned short counterCanToPoint = CanToPoint(currentPoint, vecCanToPoint);		// �������� ����� ���� �����
			for (auto element : vecCanToPoint)												// ���������� ���������� ����� ��� ����, ����� ������, �������� �� ��� ��� �������
			{
				if (canToAdjacentMove(element))
					vecCanToAdjacentMove.push_back(element);								// ��������� ��������� � ���������
			}

			if (vecCanToAdjacentMove.empty())												// ���� ���������� ��� ����������� ����� ���...
			{
				changeCell(currentPoint, this->fieldStatusVec[5]);							// ������� ����� ���������� �������.
				if (!vecTempValuePoint.empty())												// ���� ���� ��������� �������� � ������� ����������� �����...
				{
					for (auto element : vecTempValuePoint)
						changeCell(element, this->fieldStatusVec[5]);						// ...���������� �� � ������...
					vecTempValuePoint.clear();												// � ����������� ���������.
				}
				if (vecControlPoint.empty())												// ���� ����������� ����� ������ ���...
				{
					changeCell(*iterFCL, this->fieldStatusVec[0]);							// ... ���������� ���������� ����� ������ "���������"...
					changeSomeCells(7, 0);													// ... ��������������� ��� ��������� �������� � "���������" �����
					changeSomeCells(5, 0);													// ... ������ ����������
					currentPoint = entrancePnt;												// ... ���������� ������ �� �����
					freeCellList.pop_front();												// ... ��������� � ��������� ��������� �����
					iterFCL = freeCellList.begin();
					counterFCL--;
					changed = false;
					vecTempValuePoint.clear();
					continue;
				}
				else																		// ���� ����������� ����� ��� ����...
				{
					changed = true;															// ������ ������ ���������� �����, ����� �� �������� �, ���� �� �������� �����. �����
					currentPoint = vecControlPoint.back();									// ������������ �� ��������� ����������� �����
					vecControlPoint.pop_back();												// ������� � �� ���������� ���������� �����
					continue;
				}
			}
			else if (vecCanToAdjacentMove.size() == 1)										// ���� �� ����� ���� ������ ���� ������� ������
			{
				changeCell(currentPoint, this->fieldStatusVec[7]);							// ������ �� ������ �� TV - ��������� �������
				vecTempValuePoint.push_back(currentPoint);									// ��������� � � ��������� ��������� ���������
				currentPoint = vecCanToAdjacentMove.back();									// ��������� �� ������������ ��������� ��������� �����
				changed = true;
				continue;
			}
			else																			// ���� �� ����� ���� ������ 1 ������ � ��������� ������
			{
				changeCell(currentPoint, this->fieldStatusVec[4]);							// ����������� �� ������ ����������� �����
				vecControlPoint.push_back(currentPoint);									// ��������� � � ������ ����������� �����
				vecTempValuePoint.clear();
				currentPoint = vecCanToAdjacentMove.front();								// ��������� �� ������ �� ��������� ������ (�����-������-����-����� ��������� �� �����������)
				changed = true;
				continue;
			}





		//freeCellList.pop_front();																		// ��������� � ��������� ��������� �����
		//iterFCL = freeCellList.begin();
		//counterFCL--;
		//changed = false;
		// vecTempValuePoint.clear();
		// vecControlPoint.clear();
	}
	currentPoint = entrancePnt;
	changeCell(currentPoint, this->fieldStatusVec[2]);
	currentPoint = exitPnt;
	changeCell(currentPoint, this->fieldStatusVec[3]);
	//printGameField();
}

void GameField::redrawFieldWithDE(const StatusVector& pointVec)
{
	auto fieldSize = getSize();
	const StatusVector& cellStatusVec = this->fieldStatusVec;
	unsigned short x;
	unsigned short y;
	GameField DeadEnd1(fieldSize);

	unsigned short minDistance = fieldSize - 1;					// ��������� ���������� ����������� ��������� ����� ������ ����� � ������. �� ������, ���� ������ � ��������.

	if (!(fieldSize % 2))
		minDistance--;

	redrawField(pointVec);

	Point pointOfEntry(fieldSize);
	Point exitPoint(fieldSize);

	for (unsigned short i = 0; i < fieldSize; i++)
	{
		for (unsigned short j = 0; j < fieldSize; j++)
		{
			Point temp(i, j, fieldSize);
			if (getCellStatus(temp) == this->fieldStatusVec[2])
				pointOfEntry = temp;
			else if (getCellStatus(temp) == this->fieldStatusVec[3])
				exitPoint = temp;
		}
	}

	//std::cout << pointOfEntry;
	do
	{
		x = rand() % fieldSize;
		y = rand() % fieldSize;
	} while ((pointOfEntry.distanceTo(Point(x, y, fieldSize, pointVec)) < minDistance) || \
		(exitPoint.distanceTo(Point(x, y, fieldSize, pointVec)) < (minDistance / 2)));
	//std::cout << "\n" << minDistance << '\n' << pointOfEntry.distanceTo(Point(x, y, fieldSize, pointVec));
	//std::cout << pointOfEntry << Point(x, y, fieldSize, pointVec);

	Point DE1(x, y, fieldSize, pointVec);
	{
		
		GameField fieldDE1(fieldSize);
		fieldDE1.changeCell(pointOfEntry, cellStatusVec[2]);
		fieldDE1.changeCell(DE1, cellStatusVec[3]);
		fieldDE1.pointToPointAlg(pointOfEntry, DE1, cellStatusVec[0]);
		//fieldDE1.printGameField();
		fieldDE1.removeUnnecessaryCells(pointOfEntry, DE1);
		//fieldDE1.printGameField();

		for (unsigned short i = 0; i < fieldSize; i++)
		{
			for (unsigned short j = 0; j < fieldSize; j++)
			{
				Point temp(i, j, fieldSize);
				if (fieldDE1.getCellStatus(temp) == this->fieldStatusVec[0] || fieldDE1.getCellStatus(temp) == this->fieldStatusVec[3] && \
					getCellStatus(temp) != this->fieldStatusVec[2] && getCellStatus(temp) != this->fieldStatusVec[3])
					changeCell(temp, this->fieldStatusVec[0]);
				/*else if (fieldDE1.getCellStatus(temp) == this->fieldStatusVec[3])
					changeCell(temp, this->fieldStatusVec[5]);*/
			}
		}
	}
	do
	{
		x = rand() % fieldSize;
		y = rand() % fieldSize;
	} while ((pointOfEntry.distanceTo(Point(x, y, fieldSize, pointVec)) < minDistance) || \
		(exitPoint.distanceTo(Point(x, y, fieldSize, pointVec)) < (minDistance / 2)) || \
		 (DE1.distanceTo(Point(x, y, fieldSize, pointVec)) < (minDistance / 4)));

	Point DE2(x, y, fieldSize, pointVec);
	{
		GameField fieldDE2(fieldSize);
		fieldDE2.changeCell(pointOfEntry, cellStatusVec[2]);
		fieldDE2.changeCell(DE2, cellStatusVec[3]);
		fieldDE2.pointToPointAlg(pointOfEntry, DE2, cellStatusVec[0]);
		//fieldDE2.printGameField();
		fieldDE2.removeUnnecessaryCells(pointOfEntry, DE2);
		//fieldDE2.printGameField();

		for (unsigned short i = 0; i < fieldSize; i++)
		{
			for (unsigned short j = 0; j < fieldSize; j++)
			{
				Point temp(i, j, fieldSize);
				if (fieldDE2.getCellStatus(temp) == this->fieldStatusVec[0] || fieldDE2.getCellStatus(temp) == this->fieldStatusVec[3] && \
					getCellStatus(temp) != this->fieldStatusVec[2] && getCellStatus(temp) != this->fieldStatusVec[3])
					changeCell(temp, this->fieldStatusVec[0]);
				/*else if (fieldDE2.getCellStatus(temp) == this->fieldStatusVec[3])
					changeCell(temp, this->fieldStatusVec[5]);*/
			}
		}
	}
	//printGameField();
	changeSomeCells(6, 1);												//�������� ���������� "��������������������" ������ �������.
	//printGameField();
	this->vecKeyFieldPoint.clear();
	this->vecKeyFieldPoint.push_back(pointOfEntry);
	this->vecKeyFieldPoint.push_back(exitPoint);
	this->vecKeyFieldPoint.push_back(DE1);
	this->vecKeyFieldPoint.push_back(DE2);
}

const Point& GameField::getKeyPoint(unsigned short index) const
{
	assert(index < this->vecKeyFieldPoint.size() && "\n���������� ������������ ������ ������� �������� ����� ����.");
	return this->vecKeyFieldPoint[index];
}

void GameField::printKeyPoints() const
{
	if (this->vecKeyFieldPoint.empty())
	{
		std::cout << "\n�������� ����� ���� �� �������.";
		return;
	}
	auto vecSize = this->vecKeyFieldPoint.size();
	for (size_t index = 0; index < vecSize; index++)
	{
		std::cout << "\n";
		switch (index)
		{
		case 0: std::cout << "���� �� �������: " << getKeyPoint(index); break;
		case 1: std::cout << "����� � ������: " << getKeyPoint(index); break;
		case 2: 
		case 3: std::cout << "�����: " << getKeyPoint(index); break;
		default: std::cout << "������: " << getKeyPoint(index); break;
		}
	}		
}