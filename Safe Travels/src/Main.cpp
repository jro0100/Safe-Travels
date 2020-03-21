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

//Problems with deep copying the inventory pointer (using overloaded assingment operator). Need to work on
//this in FamilyMember.h.

/*
void deleteMember(std::vector<FamilyMember> &familyMember, int deleteAtIndex)
{
	std::vector<FamilyMember> newFamilyMember{};
	for (int i = 0; i < familyMember.size(); i++)
	{
		if (i != deleteAtIndex)
			newFamilyMember.push_back(familyMember[i]);
	}

	familyMember = newFamilyMember;
}
*/
int main()
{
/*
	Menu menu;
	Inventory inventory;
	std::vector<FamilyMember> familyMember{ menu.createFamilyMembers(inventory) };

	menu.displayFamilyMembers(familyMember);

	deleteMember(familyMember, 0);

//	familyMember.erase(familyMember.begin() + 1);
	std::cout << "NEW\n\n\n\n";
	menu.displayFamilyMembers(familyMember);
*/
	
	//---The following is only a short test for of the game to make sure components will work together correctly---//

	srand((unsigned)time(NULL)); //Used for random numbers in the random header file
	Menu menu;
	Journey journey;
	Date date;
	Inventory inventory;
	Merchant merchant;

	menu.welcomeMenu();
	WagonLeader wagonLeader{ menu.createWagonLeader(inventory) };
	std::vector<FamilyMember> familyMember{ menu.createFamilyMembers(inventory) };

	int familyMembersDead{ 0 };
	while (familyMembersDead < 4 || journey.getMilesRemaining() > 0)
	{
		menu.displayGameStats(date, journey);	 //Print the date and overall game mileage
		wagonLeader.displayInventory(inventory); //Print the player's inventory
		menu.displayGameOptions(journey);		 //Print the options the player can make each round

		static int choice;

		choice = (journey.getMilesToNextDest() == 100) ? getNumChoice(1, 4) : getNumChoice(1, 3);

		system("cls"); //Clear the screen
		
		switch (choice)
		{
		case(1): //View family stats
			menu.displayFamilyMembers(familyMember);
			break;
		case(2): //Stop and explore
			std::cout << "TBD";
			//Need to create good/bad outcomes of exploring. Perhaps an Exploration class
			//Bad outcomes of the exploration class can be based off the month of the year.
			break;
		case(3): //Continue on with journey
			date.increaseDate();
			journey.increaseMilesTravelled(getRandomNum(20, 50));

			for (int i = 0; i < familyMember.size(); i++)
			{
				//Runs through the round for 
				familyMember[i].runThroughRound();
				if (familyMember[i].isDead())
				{
					menu.displayDeadMember(familyMember[i]);
				//	familyMembersDead++;
				}
			}
			break;
		case(4):
			merchant.interactWithMerchant(journey, inventory, wagonLeader);
			break;
		}
	}
	
}