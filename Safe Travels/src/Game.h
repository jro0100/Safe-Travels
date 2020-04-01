#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "FamilyMember.h"
#include "Date.h"
#include "Journey.h"
#include "Menu.h"
#include "Random.h"
#include "Validation.h"
#include "Merchant.h"
#include "Exploration.h"

class Game
{
public:
	//The four choices available to the player throughout the whole game.
	enum gameChoices
	{
		VIEW_FAMILY_STATS = 1,
		STOP_AND_EXPLORE  = 2,
		USE_SUPER_PILL    = 3,
		CONTINUE_JOURNEY  = 4,
		TALK_TO_MERCHANT  = 5
	};
private:
	/*
		Use composition to create member variables of all other classes.
		
		The only two classes not included as member variables are:
			1.) WagonLeader
			2.) FamilyMember
		This is because the game does not officially start until the Game::flow() 
		member function is called so the players should not be created until then.
	*/
	Menu m_menu;
	Journey m_journey;
	Exploration m_exploration;
	Date m_date;
	Inventory m_inventory;
	Merchant m_merchant;

public:
	//-----CONSTRUCTOR-----//
	//Seeds the srand function and calls m_menu.welcomeMenu() function.
	Game();

	//Function that controls the flow of the game.
	void flow();
	
	//Called when the player has chosen to stop and explore.
	void stopAndExplore(WagonLeader &wagonLeader, std::vector<FamilyMember> &familyMember);
	//Called when the player has chosen to continue on with their travels.
	void continueJourney(std::vector<FamilyMember> &familyMember);
	void useSuperPill(WagonLeader &wagonLeader, std::vector<FamilyMember> &familyMember);
};