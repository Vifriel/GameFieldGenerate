#pragma once
#include <iostream>
#include <array>
#include <vector>

#include "Point.h"
#include "GameField.h"

class Creature
{
public:
	void printStats() const;

private:
	std::string mName;
	std::string mDesignation;
	std::string mType;
	std::array<int, 5> mStats{ 6, 6, 6, 6, 6 };
	std::array<int, 5> mResistances{ 0, 0, 0, 0, 0 };
	int mMaxHealth;
	int mHealth;
	unsigned ActionForSpeed;	//количество действий, требуемое для перемещения на 1 клетку
	//std::vector<Attack> mAttacks;	// набор атак существа
	Point mLocation;

protected:
	Creature(const GameField& field)
		: mName("SomeCreature"), 
		mDesignation("SC"), 
		mType("Untyped"), 
		mMaxHealth(1), 
		mHealth(mMaxHealth), 
		ActionForSpeed(1),
		mLocation(field.getKeyPoint(0))
	{}
	virtual ~Creature();
	virtual void move() = 0;
	virtual void attack() = 0;
	void changeName(const std::string& newName) { this->mName = newName; }
	void changeDesignation(const std::string& newDes) { this->mDesignation = newDes; }
	void changeType(const std::string& newType) { this->mType = newType; }
	virtual void changeStats(unsigned index, int value);
	virtual void changeResistance(unsigned index, int value);

	std::array<int, 5>::iterator iterStatsBegin = mStats.begin();
	std::array<int, 5>::iterator iterStatsEnd = mStats.end();
	std::array<int, 5>::iterator iterResBegin = mResistances.begin();
	std::array<int, 5>::iterator iterResEnd = mResistances.end();

};

