#pragma once
#include <iostream>
#include "Player.h"

class WagonLeader final : public Player
{
private:
	int m_cashOnHand; //Cash 
public:
	//------Constructor------//
	WagonLeader(const std::string &name, Inventory &inventory) : Player{ name, inventory }, m_cashOnHand{ 1000 } {}

	//---------Cash altering function----------//
	void changeCashOnHand(int cash);

	//----------Function member getters---------//
		//Return cash on hand
	int getCashOnHand() const;
		//Return the name of the Wagon Leader
	virtual std::string getName() const final override { return m_name; }

	//Displays the inventory of the family
	void displayInventory(const Inventory &inventory);
};