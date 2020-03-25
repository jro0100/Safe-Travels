#pragma once
#include <vector>
#include "Inventory.h"
#include "WagonLeader.h"
#include "FamilyMember.h"
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
		FAMILY_HEALED,
	};

	enum BadEvent
	{
		BAD_WEATHER,
		GET_ROBBED,
		DISEASE_BREAKS_OUT,
		WAGON_BREAKS
	};
public:
	//-----Default Constructor----//
	Exploration() = default;

	void getRandomEvent(Inventory &inventory, WagonLeader &wagonLeader, std::vector <FamilyMember> &familyMember);
	void getGoodEvent(Inventory &inventory, WagonLeader &wagonLeader, std::vector <FamilyMember> &familyMember);
	void getBadEvent(Inventory &inventory, WagonLeader &wagonLeader, std::vector <FamilyMember> &familyMember);
};