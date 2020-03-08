#pragma once
#include <iostream>
#include <vector>
#include "Inventory.h"
#include "WagonLeader.h"
#include "FamilyMember.h"

class Menu
{
public:
	//Starting menu of the game. This is only run once per game.
	void welcomeMenu();

	//Prompt player for choice from the start menu, validate that choice and return it.
	int getStartMenuChoice();

	//Display the rules of the game
	void showRules();

	//Display the about the game summary
	void aboutTheGame();

	//Get player choice for various moves in the game. TBD.
	int  getNumberChoice();

	//Prompt the player for yes or no choice, validate that choice and return it
	char getYesNoChoice();

	//Displays inventory of player
	void displayInventory(const Inventory &inventory, const WagonLeader &wagonLeader);

	//Displays family members and all their statuses.
	void displayFamilyMembers(const std::vector<FamilyMember> familyMember);
};