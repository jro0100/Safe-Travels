//-----------------------------SAFE TRAVELS---------------------//

//Game designed on 2/29/2020
//Coding began on 3/1/2020

//UPDATE (3/7/20) - Added and tested the Menu class.

#include <iostream>
#include <string>
#include <vector>
#include "Player.h"		  //Tested
#include "FamilyMember.h" //Tested
#include "Date.h"		  //Tested
#include "Journey.h"	  //Tested
#include "Menu.h"		  //Tested

int main()
{/*  ----------- Some Test Code For the Menu Class ----------
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