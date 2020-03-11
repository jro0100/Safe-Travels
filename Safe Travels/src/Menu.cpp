#include "Menu.h"

//Function Prototype: Temporarily pauses the screen for the player
void pauseScreen();


//Welcome menu for the game
void Menu::welcomeMenu()
{
	int choice{ -1 };

	//Displays a menu and prompts the player for input. 
	//The loop will terminate when the user wants to start the game (by entering 1)
	while (choice != 1)
	{
		std::cout << "\t\tSAFE TRAVELS\n"
			<< "\t---------------------------\n"
			<< "(1) Start the Game!\n"
			<< "(2) Rules\n"
			<< "(3) About the Game\n";

		//Gets validated input from the user before using it
		choice = getNumChoice(1, 3);

		//Player wants to see the rules of the game
		if (choice == 2)
			showRules();
		//Player wants to read aout the game
		else if (choice == 3)
			aboutTheGame();
	}
	//Clear the screen before exiting
	system("cls");
}


//-----------NEED TO FINISH----------//
//Displays the rules for the game.
void Menu::showRules()
{
	std::cout << "The rules are simple... To Be Updated\n";
	pauseScreen();
}

//-----------NEED TO FINISH----------//
//Displays an about the game summary.
void Menu::aboutTheGame()
{
	std::cout << "The game is simple... To Be Updated\n";
	pauseScreen();
}


//Displays the current inventory.
void Menu::displayInventory(const Inventory &inventory, const WagonLeader &wagonLeader)
{
	std::cout << "\t\tInventory\n"
		<< "\t---------------------------\n"
		<< "Cash On Hand --> " << wagonLeader.getCashOnHand() << "\n"
		<< "Food(lbs) --> " << inventory.getFoodCount() << "\n"
		<< "Medicine  --> " << inventory.getMedicineCount() << "\n"
		<< "Wagon Parts --> " << inventory.getWagonPartsCount() << "\n\n";

	pauseScreen();
}

//Displays all family members and their current statuses.
void Menu::displayFamilyMembers(const std::vector<FamilyMember> familyMember)
{
	std::cout << "\t\tFamily Members\n"
			  << "\t---------------------------\n";
	
	for (int i = 0; i < familyMember.size() ; i++)
	{
		std::cout << "Name --> " << familyMember[i].getName() << "\n"
			<< "Health --> " << familyMember[i].getHealth() << "\n"
			<< "Appetite --> " << familyMember[i].getAppetite() << "\n"
			<< "Sick Level --> " << familyMember[i].getSickWeight() << "\n\n";
	}
	pauseScreen();
}

//Temporarily pauses the screen for the player
void pauseScreen()
{
	std::cout << "Press Any Key to Return to Main Menu";
	std::cin.ignore(32767, '\n');
	std::cin.get();
	system("cls");
}