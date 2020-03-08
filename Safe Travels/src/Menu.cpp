#include "Menu.h"

//Temporarily pauses the screen for the player
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
		choice = getStartMenuChoice();

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

//Validates the choice entered by the player on the start menu.
//Only valid choices are 1(start the game), 2(Display the rules), and 3(About the game)
int Menu::getStartMenuChoice()
{
	int choice{ 0 };

	//Continuously loops until the entry is an integer between 1 and 3 inclusively
	while(true)
	{
		std::cout << "Choice --> ";
		std::cin >> choice;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
		else if (choice == 1 || choice == 2 || choice == 3)
			return choice;

		std::cout << "Error - Try again\n";
	}
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

//-----------TO BE DETERMINED----------//
//Checks if the player entered a valid choice while playing the game.
//This member function will be used throughout the game as a means for the
//player to make choices. This may be changed/deleted in future design. TBD.
int Menu::getNumberChoice()
{
	return 0;
}

//Prompts the player for yes or no input and then validates that input before returning it.
char Menu::getYesNoChoice()
{
	char yesOrNoChoice{};

	//Continously loops until the player enters valid input (Y,y,N,n)
	while (true)
	{
		std::cout << "Choice (Y/N) --> ";
		std::cin >> yesOrNoChoice;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
		else if (yesOrNoChoice == 'Y' || yesOrNoChoice == 'y' || yesOrNoChoice == 'N' || yesOrNoChoice == 'n')
			return toupper(yesOrNoChoice); //Force the character to uppercase before returning it.

		std::cout << "Error - Try again\n";
	}
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