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
		std::cout << "\t\t\tSAFE TRAVELS\n"
			<< "\t\t     ------------------\n\n"
			<< "(1) Start the Game!\n"
			<< "(2) How to Play\n"
			<< "(3) About the Game\n\n";

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
	std::cout << "\t\t\tHow to Play\n"
		<< "\t\t     -----------------\n\n"
		<< "1.) You are travelling "
		<< "across the country in a wagon.\n\n2.) You, the wagon leader, "
		<< "make all decisions in the game.\n\n3.) You have four family members: "
		<< "your wife and three kids.\n\n4.) Your family members each have health, appetite, "
		<< "and sick-\n    weight. The larger the sick-weight, the larger the\n    appetite, "
		<< "which leads to higher food consumption from that    family member. Health is also decreased each"
		<< " round based      on the family members sick-weight.\n\n"
		<< "5.) You must make is across the country without your family\n    dying to win the game.\n\n"
		<< "6.) If all members of your family die before your journey\n    ends, you lose the game.\n\n"
		<< "7.) Every 100 miles of travel, you will reach a landmark. Upon    reaching this landmark, "
		<< "you can buy from or sell to the\n    merchant. You must keep a well-stocked inventory "
		<< "to keep\n    your family alive.\n\n"
		<< "Good Luck!\n\n";
	pauseScreen();
}

//-----------NEED TO FINISH----------//
//Displays an about the game summary.
void Menu::aboutTheGame()
{
	system("cls");
	std::cout << "\t\t\tAbout the Game\n"
		<< "\t\t     --------------------\n\n"
		<< "Author: jro0100\n\nGame Started: February 29, 2020\nGame Finished: Date Not Yet Known\n\n"
		<< "This is meant to be a spin-off of the popular 80's game\ncalled \"The Oregon Trail\"\n\n"
		<< "Enjoy!\n\n";
	pauseScreen();
}

//Creates the wagon leader (main player) of the game
WagonLeader Menu::createWagonLeader(Inventory &inventory)
{
	std::cout << "\t\t   Create Family\n"
		<< "\t\t-------------------\n\n"
		<< "Welcome traveler!\nEnter your name --> ";
	std::string name;
	std::cin.ignore(32767, '\n');
	std::getline(std::cin, name);
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
			std::cout << "Enter your wife's name? --> ";
		else if (i == 1)
			std::cout << "Enter your son's name(Age 6)? --> ";
		else if (i == 2)
			std::cout << "Enter your daughter's name(Age 10)? --> ";
		else if (i == 3)
			std::cout << "Enter your son's name(Age 13)? --> ";

		std::getline(std::cin, name);
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
		std::cout << "\tName: " << familyMember[i].getName() << "\n"
			<< "\tHealth: " << familyMember[i].getHealth() << "\n"
			<< "\tAppetite: " << familyMember[i].getAppetite() << "\n"
			<< "\tSick Level: " << familyMember[i].getSickWeight() << "\n\n";
	}
	//pauseScreen();
}

//Notifies the player that a family member has died. Displays the stats of that dead family member.
void Menu::displayDeadMember(FamilyMember &familyMember)
{
		system("cls");
		std::cout << "\t\tDeath in Family\n"
			<< "\t        ------------------\n"
			<< familyMember.getName() << " has died!\n\n"
			<< "\tHealth --> " << familyMember.getHealth() << "\n"
			<< "\tAppetite --> " << familyMember.getAppetite() << "\n"
			<< "\tSick Level --> " << familyMember.getSickWeight() << "\n\n";

		pauseScreen();
}

//Displays the game stats such as date, total miles travelled, miles reamaining, and miles to next destination.
void Menu::displayGameStats(const Date &date, const Journey &journey) const
{
	//Print the date, total miles travelled, miles reamaining, and miles to next destination
	std::cout << "\t\tProgression\n"
		<< "\t---------------------------\n"
		<<"\tDate: " << date << "\n"
		<< "\tMiles Travelled: " << journey.getMilesTravelled() << "\n"
		<< "\tMiles Remaining: " << journey.getMilesRemaining() << "\n"
		<< "\tMiles to next Landmark: " << journey.getMilesToNextDest() << "\n\n";
}

//Displays the options for the player each round while the game is running
void Menu::displayGameOptions(const Journey &journey) const 
{	
	std::cout << "\t\t   Options\n"
		<< "\t----------------------------\n"
		<< "\t(1) View family stats\n"
		<< "\t(2) Stop and explore\n"
		<< "\t(3) Use a Super Pill\n"
		<< "\t(4) Continue on with journey\n";
	
	//If the next destination has been reached, the player can see the merchant.
	//A destination will be reached every 100 miles
	if (journey.getMilesToNextDest() == 100)
		std::cout << "\t(5) Interact with the merchant\n\n";
}

//Temporarily pauses the screen for the player
void pauseScreen()
{
	std::cout << "Press Any Key to Continue";
	std::cin.ignore(32767, '\n');
	std::cin.get();
	system("cls");
}