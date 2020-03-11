#pragma once
#include <iostream>
#include "Inventory.h"
#include "WagonLeader.h"
#include "Pricing.h"
#include "Random.h"
#include "Validation.h"

/*---------------WORK IN PROGRESS---------------*/

/*
	
	When the player interacts with the merchant, the interactWithMerchant(WagonLeader&) will be called. 
	This function will call the proper functions to refresh the merchant's pricing and inventory and 
	then interact with the user. Buying an item will result in the buyItem(WagonLeader&) function
	being called where selling an item will call the sellItem(WagonLeader&) function from the Merchant class.
	These functions will make all the necessary checks (via the universal validation function) before proceeding 
	with the purchase or sale.

	This is still a work in progress and is subject to change.
*/

/*
	The player can interact with the merchant at each stop during their travels.
	The player can buy or sell to the merchant.
	A merchant instantiation will only be created once throughout the game.
	The merhcants buying and selling prices will differ at each stop.
*/
class Merchant
{
private:
	Inventory m_inventory;
	Pricing m_pricing;
public:
	//--------Constructor---------//
	Merchant() : m_inventory{ 100, 50, 20 } {}

	void buyItems(Inventory &inventory, WagonLeader &wagonLeader); //Interface for purchasing an item
	void sellItems(Inventory &inventory, WagonLeader &wagonLeader); //Interface for selling an item
	void setRandomInventory(); //Randomly resets the merchants inventory when called
	void interactWithMerchant(Inventory &inventory, WagonLeader &wagonLeader); //Main function for interacting with player
};