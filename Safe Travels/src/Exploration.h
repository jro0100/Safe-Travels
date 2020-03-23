#pragma once
#include "Inventory.h"
#include "WagonLeader.h"
#include "Random.h"

class Exploration
{
public:
	enum EventType
	{
		GOOD,
		BAD
	};

	enum GoodEvent
	{
		FIND_MONEY,
		FIND_FOOD,
		FIND_MEDICINE,
		FIND_WAGON_PARTS,
		FAMILY_HEALED
	};

	enum BadEvent
	{
		BAD_WEATHER,
		GET_ROBBED,
		WAGON_BREAKS
	};
public:
	//-----Default Constructor----//
	Exploration() = default;

	void getRandomEvent(Inventory &inventory, WagonLeader &wagonLeader);
	void getGoodEvent(Inventory &inventory, WagonLeader &wagonLeader);
	void getBadEvent(Inventory &inventory, WagonLeader &wagonLeader);
};