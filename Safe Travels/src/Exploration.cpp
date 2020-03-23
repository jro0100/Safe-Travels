#include "Exploration.h"

void Exploration::getRandomEvent(Inventory &inventory, WagonLeader &wagonLeader)
{
	EventType eventType = static_cast<EventType>(getRandomNum(0, 1));

	switch (eventType)
	{
	case (GOOD):
		getGoodEvent(inventory, wagonLeader);
		break;
	case(BAD):
		getBadEvent(inventory, wagonLeader);
		break;
	}
}
void Exploration::getGoodEvent(Inventory &inventory, WagonLeader &wagonLeader)
{
	GoodEvent goodEventType = static_cast<GoodEvent>(getRandomNum(0, 4));

	switch (goodEventType)
	{
	case(FIND_MONEY):
		//TODO
		break;
	case(FIND_FOOD):
		//TODO
		break;
	case(FIND_MEDICINE):
		//TODO
		break;
	case(FIND_WAGON_PARTS):
		//TODO
		break;
	case(FAMILY_HEALED):
		//TODO
		break;
	}
	system("cls");
}
void Exploration::getBadEvent(Inventory &inventory, WagonLeader &wagonLeader)
{
	BadEvent badEventType = static_cast<BadEvent>(getRandomNum(0, 2));

	switch (badEventType)
	{
	case(BAD_WEATHER):
		//TODO
		break;
	case(GET_ROBBED):
		//TODO
		break;
	case(WAGON_BREAKS):
		//TODO
		break;
	}
	system("cls");
}