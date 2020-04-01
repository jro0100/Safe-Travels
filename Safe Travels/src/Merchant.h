#pragma once
#include <iostream>
#include "Inventory.h"
#include "WagonLeader.h"
#include "Pricing.h"
#include "Journey.h"
#include "Random.h"
#include "Validation.h"

/*
	TODO: Need to add comments to the member functions of Merchant.cpp.
*/

/*
					-------A Few Things to Keep in Mind for the Merchant-------
	1.) The player can interact with the merchant at each stop during their travels.

	2.) The player can buy or sell to the merchant.

	3.) A merchant instantiation will only be created once throughout the game.

	4.) The merhcants buying and selling prices will differ at each stop.
*/
class Merchant
{
public:
	//Holds the two options that the player can choose from when talking to merchant
	enum buyOrSell
	{
		BUY  = 1,
		SELL = 2
	};

	//Holds the three items that the buy can buy or sell
	enum buySellItems
	{
		FOOD	    = 1,
		MEDICINE	= 2,
		WAGON_PARTS = 3,
		SUPER_PILL  = 4,
		EXIT		= 5
	};
private:
	//The merchant holds his own inventory
	Inventory m_inventory;
	
	//The merchant refers to the pricing object for all item prices
	Pricing m_pricing;
public:
	//--------Constructor---------//
	Merchant() : m_inventory{ 100, 100, 100, 100 } {}

	//Interface for purchasing an item
	void buyOrSellItems(Inventory &inventory, WagonLeader &wagonLeader, buyOrSell choice);
	
	//Main function for interacting with player
	void interactWithMerchant(const Journey &journey, Inventory &inventory, WagonLeader &wagonLeader);

	//Does all the backend work for buying and selling an item
	void makePurchase(Inventory &inventory, WagonLeader &wagonLeader, buyOrSell buyOrSellChoice, buySellItems buySellItem);

	//Prints the merchants inventory to the screen
	void printMerchantsInventory();

	//Randomly resets the inventory of the merchant. The merchants inventory is reset each visit.
	void setRandomInventory();
};