#pragma once
#include <iostream>
#include <vector>
#include "Inventory.h"
#include "WagonLeader.h"
#include "FamilyMember.h"
#include "Validation.h"
#include"Date.h"
#include "Journey.h"

class Menu
{
public:
	//Starting menu of the game. This method is only called once per game.
	void welcomeMenu();

	//Display the rules of the game
	void showRules();

	//Display the about the game summary
	void aboutTheGame();

	//Creates the wagon leader (main player) of the game. This method is only called once per game.
	WagonLeader createWagonLeader(Inventory &inventory);

	//Creates the family members of the game. This method is only called once per game.
	std::vector<FamilyMember> createFamilyMembers(Inventory &inventory);

	//Displays family members and all their statuses
	void displayFamilyMembers(const std::vector<FamilyMember> familyMember);

	//Notifies the player that a family member has died. Displays the stats of that dead family member.
	void displayDeadMember(FamilyMember &familyMember);

	//Displays the game stats such as date, total miles travelled, miles reamaining, and miles to next destination.
	void displayGameStats(const Date &date, const Journey &journey) const;

	//Displays the options for the player each round while the game is running
	void displayGameOptions(const Journey &journey) const;
};