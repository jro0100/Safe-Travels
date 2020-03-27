#include "Game.h"

Game::Game()
{
	//Seed srand to generate random numbers in the game
	srand((unsigned)time(NULL));
	//Welcome menu displayed before the game begins
	m_menu.welcomeMenu();
}

void Game::flow()
{
	//Create the wagon leader and family members
	WagonLeader wagonLeader{ m_menu.createWagonLeader(m_inventory) };
	std::vector<FamilyMember> familyMember{ m_menu.createFamilyMembers(m_inventory) };

	while (true)
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
			gameChoice = static_cast<gameChoices>(getNumChoice(1, 4));
		//The player has not reached the next destination and does not have a choice of seeing the merchant
		else
			gameChoice = static_cast<gameChoices>(getNumChoice(1, 3));

		//Clear the screen
		system("cls");

		//Take action based off what the player's choice was
		switch (gameChoice)
		{
		case(VIEW_FAMILY_STATS):
			m_menu.displayFamilyMembers(familyMember);
			break;
		case(STOP_AND_EXPLORE):
			stopAndExplore(wagonLeader, familyMember);
			break;
		case(CONTINUE_JOURNEY):
			continueJourney(familyMember);
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

//Makes the necessary calls to continue on with the journey
void Game::continueJourney(std::vector<FamilyMember> &familyMember)
{
	//Increases the date
	m_date.increaseDate();
	//Increases the distance by a random number between 20 and 50
	m_journey.increaseMilesTravelled(getRandomNum(20, 50));

	//Runs through a round for each family member
	for (int i = 0; i < familyMember.size(); i++)
	{
		familyMember[i].runThroughRound();
		
		//If player died, display the death on the screen
		if (familyMember[i].isDead())
			m_menu.displayDeadMember(familyMember[i]);
	}
}