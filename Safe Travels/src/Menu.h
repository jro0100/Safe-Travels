#pragma once
#include <iostream>
#include <vector>
#include "Inventory.h"
#include "WagonLeader.h"
#include "FamilyMember.h"
#include "Validation.h"

class Menu
{
public:
	//Starting menu of the game. This is only run once per game.
	void welcomeMenu();

	//Display the rules of the game
	void showRules();

	//Display the about the game summary
	void aboutTheGame();

	//Displays inventory of player
	void displayInventory(const Inventory &inventory, const WagonLeader &wagonLeader);

	//Displays family members and all their statuses.
	void displayFamilyMembers(const std::vector<FamilyMember> familyMember);
};