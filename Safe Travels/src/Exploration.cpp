#include "Exploration.h"

void familyHealthChange(std::vector<FamilyMember> &familyMember, int healthAdded, int sickWeightAdded)
{
	for (int i = 0; i < familyMember.size(); i++)
	{
		if (familyMember[i].getHealth() > 0)
		{
			familyMember[i].changeHealth(healthAdded);
			familyMember[i].changeSickness(sickWeightAdded);
		}
	}
}

std::string getDiseaseName()
{
	int randomDiseaseName{ getRandomNum(1, 10) };

	switch (randomDiseaseName)
	{
	case(1):
		return "SARS";
		break;
	case(2):
		return "COVID-19";
		break;
	case(3):
		return "Ebola";
		break;
	case(4):
		return "Leprosy";
		break;
	case(5):
		return "Polio";
		break;
	}
}

void wagonPartsAvailability(Inventory &inventory, WagonLeader &wagonLeader, const int wagonPartsNeeded)
{
	if (inventory.getWagonPartsCount() >= wagonPartsNeeded)
	{
		inventory.changeWagonPartsCount(-wagonPartsNeeded);
		
		std::cout << "Wagon Parts Used: " << wagonPartsNeeded
			<< "\nWagon Parts Remaining: " << inventory.getWagonPartsCount() << "\n\n";
	}
	else if (wagonLeader.getCashOnHand() < 150)
	{
		int foodLost{ getRandomNum(inventory.getFoodCount() * 0.3, inventory.getFoodCount() * 0.4) };
		int medicineLost{ getRandomNum(inventory.getFoodCount() * 0.3, inventory.getMedicineCount() * 0.4) };

		inventory.changeFoodCount(-foodLost);
		inventory.changeMedicineCount(-medicineLost);

		std::cout << "Oops, you do not have enough\nwagon parts or money to fix this.\n\n"
			<< "You are forced to pay in food and medicine.\n"
			<< "Food Lost: " << foodLost
			<< "\nMedicine Lost: " << medicineLost
			<< "\nFood Remaining: " << inventory.getFoodCount()
			<< "\nMedicine Remaining: " << inventory.getMedicineCount() << "\n\n";
	}
	else
	{
		wagonLeader.changeCashOnHand(-150);

		std::cout << "Oops, you do not have enough wagon parts to fix this.\n\n"
			<< "\nThis will cost you 150 dollars.\n"
			<< "Cash Lost: 150 dollars\n"
			<< "Cash Remaining: " << wagonLeader.getCashOnHand() << "\n\n";
	}
}

void Exploration::getRandomEvent(Inventory &inventory, WagonLeader &wagonLeader, std::vector <FamilyMember> &familyMember)
{
	std::cout << "\t\tExploration\n"
		<< "\t   ---------------------\n\n";
	EventType eventType = static_cast<EventType>(getRandomNum(0, 1));

	switch (eventType)
	{
	case (GOOD):
		getGoodEvent(inventory, wagonLeader, familyMember);
		break;
	case(BAD):
		getBadEvent(inventory, wagonLeader, familyMember);
		break;
	}
}
void Exploration::getGoodEvent(Inventory &inventory, WagonLeader &wagonLeader, std::vector <FamilyMember> &familyMember)
{
	GoodEvent goodEventType = static_cast<GoodEvent>(getRandomNum(0, 4));

	switch (goodEventType)
	{
	case(FIND_MONEY):
	{
		int moneyFound{ getRandomNum(70, 400) };

		wagonLeader.changeCashOnHand(moneyFound);

		std::cout << "You found money!\n"
			<< "Amount Found: " << moneyFound
			<< "\nNew cash on hand: " << wagonLeader.getCashOnHand() << "\n\n";
		break;
	}
	case(FIND_FOOD):
	{
		int foodFound{ getRandomNum(10, 50) };

		inventory.changeFoodCount(foodFound);

		std::cout << "You found food!\n"
			<< "\nAmount Found: " << foodFound
			<< "\nNew food on hand: " << inventory.getFoodCount() << "\n\n";
		break;
	}
	case(FIND_MEDICINE):
	{
		int medicineFound{ getRandomNum(10, 50) };

		inventory.changeMedicineCount(medicineFound);

		std::cout << "You found medicine!\n"
			<< "Amount Found: " << medicineFound
			<< "\nNew medicine on hand: " << inventory.getMedicineCount() << "\n\n";
		break;
	}
	case(FIND_WAGON_PARTS):
	{
		int wagonPartsFound{ getRandomNum(10, 50) };

		inventory.changeWagonPartsCount(wagonPartsFound);

		std::cout << "You found wagon parts!\n"
			<< "Amount Found: " << wagonPartsFound
			<< "\nNew wagon parts on hand: " << inventory.getWagonPartsCount() << "\n\n";
		break;
	}
	case(FAMILY_HEALED):
	{
		int healthAdded{ getRandomNum(5, 20) };
		int sickWeightDeducted{ getRandomNum(1, 3) };

		familyHealthChange(familyMember, healthAdded, sickWeightDeducted);

		std::cout << "You come across a kind stranger!\n"
			<< "You are given a magic powder by this stranger.\n\n"
			<< "Each family member earns " << healthAdded << " health points\n"
			<< "Each family member drops " << sickWeightDeducted << " sick weight points\n\n";
		break;
	}
	}
	std::cout << "Press any key to continue";
	std::cin.ignore(32767, '\n');
	std::cin.get();
	system("cls");
}
void Exploration::getBadEvent(Inventory &inventory, WagonLeader &wagonLeader, std::vector <FamilyMember> &familyMember)
{
	BadEvent badEventType = static_cast<BadEvent>(getRandomNum(0, 3));

	switch (badEventType)
	{
	case(BAD_WEATHER):
	{
		std::cout << "Bad Weather\n\n"
			<< "NEED TO FINISH";
		//TODO
		break;
	}
	case(GET_ROBBED):
	{
		int foodLost{ getRandomNum(inventory.getFoodCount() * 0.05, inventory.getFoodCount() * 0.2) };
		int medicineLost{ getRandomNum(inventory.getFoodCount() * 0.05, inventory.getMedicineCount() * 0.2) };
		int wagonPartsLost{ getRandomNum(inventory.getFoodCount() * 0.05, inventory.getWagonPartsCount() * 0.2) };

		inventory.changeFoodCount(-foodLost);
		inventory.changeMedicineCount(-medicineLost);
		inventory.changeWagonPartsCount(-wagonPartsLost);

		std::cout << "You come across a stranger who robs you.\n"
			<< "Food Lost: " << foodLost
			<< "\nMedicine Lost: " << medicineLost
			<< "\nWagon Parts Lost: " << wagonPartsLost << "\n\n";

		wagonLeader.displayInventory(inventory);
		break;
	}
	case(DISEASE_BREAKS_OUT):
	{
		int healthDeducted{ getRandomNum(2, 10) };
		int sickWeightAdded{ 1 };

		familyHealthChange(familyMember, -healthDeducted, -sickWeightAdded);

		std::cout << "A disease named " << getDiseaseName() << " has infected your family.\n"
			<< "Each family member loses " << healthDeducted << " health points.\n"
			<< "Each family member gains " << sickWeightAdded << "sick weight point\n\n";
		break;
	}
	case(WAGON_BREAKS):
	{
		int wagonPartsNeeded{ getRandomNum(1, 3) };
		std::cout << "Your wagon breaks down and needs " << wagonPartsNeeded
			<< " wagon parts to fix it.\n";

		wagonPartsAvailability(inventory, wagonLeader, wagonPartsNeeded);
		break;
	}
	}
	std::cout << "Press any key to continue";
	std::cin.ignore(32767, '\n');
	std::cin.get();
	system("cls");
}