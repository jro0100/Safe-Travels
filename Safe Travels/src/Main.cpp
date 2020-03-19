//-----------------------------SAFE TRAVELS---------------------//

//Game designed on 2/29/2020
//Coding began on 3/1/2020

//Update (3/7/20)  - Added and tested the Menu class.
//Update (3/12/20) - Updated the Merchant class

#include <iostream>
#include <string>
#include <vector>
#include "Player.h"		  //Tested
#include "FamilyMember.h" //Tested
#include "Date.h"		  //Tested
#include "Journey.h"	  //Tested
#include "Menu.h"		  //Tested
#include "Random.h"		  //Tested
#include "Validation.h"
#include "Merchant.h"

void memberDied(const FamilyMember &familyMember)
{
	system("cls");
	std::cout << "\t\tDeath in Family\n"
		<< "\t\t----------------\n"
		<< familyMember.getName() << " has died!\n\n"
		<< "Health --> " << familyMember.getHealth() << "\n"
		<< "Appetite --> " << familyMember.getAppetite() << "\n"
		<< "Sick Level --> " << familyMember.getSickWeight() << "\n\n";
	std::cout << "Press any key to continue";
	std::cin.ignore(32767, '\n');
	std::cin.get();
	system("cls");
}

int main()
{
	//---The following is only a short test for of the game to make sure components will work together correctly---//

	srand((unsigned)time(NULL)); //Used for random numbers in the random header file
	Menu menu;
	menu.welcomeMenu();	
	Journey journey;
	Date date;
	Inventory inventory;
	Merchant merchant;

	std::cout << "Welcome traveler, enter your name --> ";
	std::string name;
	std::cin >> name;
	
	//----CREATE FAMILY----//
	WagonLeader wagonLeader(name, inventory);
	std::vector<FamilyMember> familyMember{};
	for (int i = 0; i < 4; i++)
	{
		if (i == 0)
			std::cout << "What is your wife's name? --> ";
		else if (i == 1)
			std::cout << "What is your 6 year old son's name? --> ";
		else if (i == 2)
			std::cout << "What is your 10 year old daughter's name? --> ";
		else if (i == 3)
			std::cout << "What is your 13 year old son's name? --> ";
			
			std::cin >> name;
			familyMember.push_back(FamilyMember{ name, inventory });
	}

	system("cls");

	while (true)
	{
		std::cout << "\tDate --> " << date << "\n"
			<< "\tTotal Miles Travelled --> " << journey.getMilesTravelled() << "\n"
			<< "\tMiles Remaining --> " << journey.getMilesRemaining() << "\n"
			<< "\tMiles to next Destination --> " << journey.getMilesToNextDest() << "\n"
			<< "\t-------------------------------\n"
			<< "(1) View family stats\n"
			//Need to create good/bad outcomes of exploring. Perhaps an Exploration class
			//Bad outcomes of the exploration class can be based off the month of the year.
			<< "(2) Stop and explore\n"
			<< "(3) Continue on your journey\n";
		if (journey.getMilesToNextDest() == 100)
			std::cout << "(4) Interact with the merchant\n";

		std::cout << "\n";

		int choice;
		if (journey.getMilesToNextDest() == 100)
			choice = getNumChoice(1, 4);
		else
			choice = getNumChoice(1, 3);
		
		system("cls");
		
		switch (choice)
		{
		case(1):
			menu.displayFamilyMembers(familyMember);
			break;
		case(2):
			std::cout << "TBD";
			break;
		case(3):
			date.increaseDate();
			journey.increaseMilesTravelled(getRandomNum(20, 50));

			for (int i = 0; i < familyMember.size(); i++)
			{
				//Runs through the round for 
				familyMember[i].runThroughRound();
				if (familyMember[i].isDead())
				{
					memberDied(familyMember[i]);
					//familyMember.erase(familyMember.begin() + i);
				}
			}
			break;
		case(4):
			merchant.interactWithMerchant(journey, inventory, wagonLeader);
			break;
		}
	
	}

	/*  ----------- Some Test Code For the Menu Class ----------
	Menu menu;
	menu.welcomeMenu();

	std::string name{"Justin"};

	Inventory inventory;
	WagonLeader wagonLeader(name, inventory);

	menu.displayInventory(inventory, wagonLeader);

	std::vector<FamilyMember> familyMembers;
	for (int i = 0; i < 4; i++)
	{
		FamilyMember member{ "Kayleigh", inventory };
		familyMembers.push_back(member);
	}

	menu.displayFamilyMembers(familyMembers);

	*/

	/*	-------NOTES TO KEEP IN MIND WHEN DEVELOPING THE GAME-------

		1.) Keep a vector of pointers to the Family Member class

		2.) Keep a single Wagon Leader object floating around the game, 
			this object will be passed in classes such as the Menu class 
			(showInventory() function) and the merchant class

		3.) Keep a inventory object floating around the game, which will 
			be passed into to be used in some of the classes such as the 
			Menu class (showInventory() function) and the Merchant class
	*/
}