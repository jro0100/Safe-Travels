#include "Game.h"

void pause();

Game::Game()
{
	//Seed srand to generate random numbers in the game
	srand((unsigned)time(NULL));
	
	//Welcome menu displayed before the game begins
	m_menu.welcomeMenu();
	
	//Game has officially started
	m_gameOverType = GAME_NOT_COMPLETED;
}

Game::~Game()
{
	system("cls");
	std::cout << "\t\t\tGame Over\n" << "\t\t------------------------\n\n";

	switch (m_gameOverType)
	{
	case(FAMILY_MEMBERS_DEAD):
		std::cout << "\tSadly, All Members of your Family have Died";
		break;
	case(END_OF_JOURNEY_REACHED):
		std::cout << "Congratulations! You have successfully completed the journey!";
		break;
	default:
		std::cout << "    An unknown error has occured causing the game to end";
		break;
	}

	std::cout << "\n\n\n\t\t\tMonth: " << m_date.getMonth() << "\n\t\t\tWeek: " 
			  << m_date.getWeek() << "\n\t\t\tYear: " << m_date.getYear() 
			  << "\n\n" << "\t\t   Miles Travelled: " << m_journey.getMilesTravelled() 
			  << "\n" << "\t\t   Miles Remaining: " << m_journey.getMilesRemaining() << "\n\n\n";

	std::cout << "\t  ----------------------------------\n" << "\t   THANKS FOR PLAYING SAFE TRAVELS\n"
			  << "\t  ----------------------------------\n";

	std::cin.get();
}

void Game::flow()
{
	//Create the wagon leader and family members
	WagonLeader wagonLeader{ m_menu.createWagonLeader(m_inventory) };
	std::vector<FamilyMember> familyMember{ m_menu.createFamilyMembers(m_inventory) };

	while (m_gameOverType == GAME_NOT_COMPLETED)
	{
		//Print the date and overall game mileage
		m_menu.displayGameStats(m_date, m_journey);
		//Print the player's inventory	
		wagonLeader.displayInventory(m_inventory);
		//Print the options the player can make each round
		m_menu.displayGameOptions(m_journey);

		//Create a static choice of type enum
		static gameChoices gameChoice;

		//If the player has reached the next destination, offer a choice to see the merchant
		if (m_journey.getMilesToNextDest() == 100)
			gameChoice = static_cast<gameChoices>(getNumChoice(1, 5));
		//The player has not reached the next destination and does not have a choice of seeing the merchant
		else
			gameChoice = static_cast<gameChoices>(getNumChoice(1, 4));

		//Clear the screen
		system("cls");

		//Take action based off what the player's choice was
		switch (gameChoice)
		{
		case(VIEW_FAMILY_STATS):
			m_menu.displayFamilyMembers(familyMember);
			pause();
			break;
		case(STOP_AND_EXPLORE):
			stopAndExplore(wagonLeader, familyMember);
			break;
		case(USE_SUPER_PILL):
			useSuperPill(wagonLeader, familyMember);
			break;
		case(CONTINUE_JOURNEY):
			m_gameOverType = continueJourney(familyMember);
			break;
		case(TALK_TO_MERCHANT):
			m_merchant.interactWithMerchant(m_journey, m_inventory, wagonLeader);
			break;
		}
	}
}

//Makes the necessarry calls to let the player explore
void Game::stopAndExplore(WagonLeader &wagonLeader, std::vector<FamilyMember> &familyMember)
{
	//If the player has moved since last exploring, allow an event to happen
	if (m_journey.checkPlayerMoved())
		m_exploration.getRandomEvent(m_inventory, wagonLeader, familyMember);
	//The player has not moved and therefore can not explore the same area twice
	else
		m_exploration.areaAlreadyExplored();
}

//Makes the necessary calls to continue on with the journey. True is returned
//if the game ends due to all family members dead or reaching the end of the journey.
Game::gameOverType Game::continueJourney(std::vector<FamilyMember> &familyMember)
{
	//Increases the date
	m_date.increaseDate();
	//Increases the distance by a random number between 20 and 50
	m_journey.increaseMilesTravelled(getRandomNum(20, 50));

	//Counts the number of family members that have died throughout the game
	static int familyMembersDead{};
	//Return whether the game has ended or not
	gameOverType gameOver{ GAME_NOT_COMPLETED };

	//Runs through a round for each family member that is not dead
	for (int i = 0; i < familyMember.size(); i++)
	{
		//If player died, display the death on the screen
		if (familyMember[i].isDead() && familyMember[i].getHealth() != -1)
		{
			m_menu.displayDeadMember(familyMember[i]);
			familyMember[i].changeHealth(-1);
			familyMember[i].markAsDead();
			//Increase the family member death count
			familyMembersDead++;
		}
		else if(familyMember[i].getHealth() != -1)
			familyMember[i].runThroughRound();
	}

	//If the family member death count equals total number of family members
	if (familyMembersDead == familyMember.size())
		gameOver = FAMILY_MEMBERS_DEAD;
	//If the journey of the player has ended
	else if (m_journey.getMilesRemaining() <= 0)
		gameOver = END_OF_JOURNEY_REACHED;
	//Else, the game has not yet been completed
	else
		gameOver = GAME_NOT_COMPLETED;

	return gameOver;
}


void Game::useSuperPill(WagonLeader &wagonLeader, std::vector<FamilyMember> &familyMember)
{
	if (m_inventory.getSuperPillCount() > 0 && familyMember.size() > 0)
	{
		m_menu.displayFamilyMembers(familyMember);
		std::cout << "\tSelect a family member heal:\n";

		int choiceNum{};
		for (choiceNum = 0; choiceNum < familyMember.size(); choiceNum++)
			std::cout << "\t(" << (choiceNum + 1) << ") " << familyMember[choiceNum].getName() << "\n";
		std::cout << "\t(" << choiceNum + 1 << ") Exit\n";

		int choice{};
		choice = getNumChoice(1, familyMember.size() + 1);

		if (choice != (choiceNum + 1))
		{
			familyMember[choice - 1].changeHealth(100);
			familyMember[choice - 1].changeSickness(-5);
			m_inventory.useSuperPill();

			std::cout << "\nFamily Member Successfully Healed!\n\n";
		}
	}
	else
	{
		std::cout << "\t\tUse Super Pill\n"
			<< "\t    --------------------\n\n"
			<< "*Error* - Inventory contains no super pills.\n\n";

	}
	pause();
}

void pause()
{
	std::cout << "Press any key to Return";
	std::cin.ignore(32767, '\n');
	std::cin.get();
	system("cls");
}