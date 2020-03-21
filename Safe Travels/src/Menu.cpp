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
	system("cls");
	std::cout << "\t\tGame Rules\n"
		<< "\t--------------------------\n"
		<< "The rules are simple... To Be Updated\n";
	pauseScreen();
}

//-----------NEED TO FINISH----------//
//Displays an about the game summary.
void Menu::aboutTheGame()
{
	system("cls");
	std::cout << "\t\tAbout the Game\n"
		<< "\t---------------------------\n"
		<< "The game is simple... To Be Updated\n";
	pauseScreen();
}

//Creates the wagon leader (main player) of the game
WagonLeader Menu::createWagonLeader(Inventory &inventory)
{
	std::cout << "Welcome traveler, enter your name --> ";
	std::string name;
	std::cin >> name;
	return WagonLeader{ name, inventory };
}

//Creates the family members of the game. This method is only called once per game.
std::vector<FamilyMember> Menu::createFamilyMembers(Inventory &inventory)
{
	std::string name;
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

	//Clear the screen
	system("cls");

	return familyMember;
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

//Notifies the player that a family member has died. Displays the stats of that dead family member.
void Menu::displayDeadMember(const FamilyMember &familyMember) const
{
	system("cls");
	std::cout << "\t\tDeath in Family\n"
		<< "\t      ------------------\n"
		<< familyMember.getName() << " has died!\n\n"
		<< "Health --> " << familyMember.getHealth() << "\n"
		<< "Appetite --> " << familyMember.getAppetite() << "\n"
		<< "Sick Level --> " << familyMember.getSickWeight() << "\n\n";
	
	pauseScreen();
}

//Displays the game stats such as date, total miles travelled, miles reamaining, and miles to next destination.
void Menu::displayGameStats(const Date &date, const Journey &journey) const
{
	//Print the date, total miles travelled, miles reamaining, and miles to next destination
	std::cout << "\t\tProgression\n"
		<< "\t----------------------------\n"
		<<"\tDate: " << date << "\n"
		<< "\tTotal Miles Travelled: " << journey.getMilesTravelled() << "\n"
		<< "\tMiles Remaining --> " << journey.getMilesRemaining() << "\n"
		<< "\tMiles to next Destination: " << journey.getMilesToNextDest() << "\n\n";
}

//Displays the options for the player each round while the game is running
void Menu::displayGameOptions(const Journey &journey) const 
{	
		std::cout << "\t\t   Options\n"
			<< "\t   ---------------------\n"
			<< "(1) View family stats\n"
			<< "(2) Stop and explore\n"
			<< "(3) Continue on with journey\n";
	
	//If the next destination has been reached, the player can see the merchant.
	//A destination will be reached every 100 miles
	if (journey.getMilesToNextDest() == 100)
		std::cout << "(4) Interact with the merchant\n\n";
}

//Temporarily pauses the screen for the player
void pauseScreen()
{
	std::cout << "Press Any Key to Continue";
	std::cin.ignore(32767, '\n');
	std::cin.get();
	system("cls");
}