#pragma once
#include <iostream>
#include "Random.h"

class Pricing
{
private:
	int m_buyFoodPrice{ 5 };		 //Merchant's food buying price
	int m_buyMedicinePrice{ 5 };     //Merchant's medicine buying price
	int m_buyWagonPartsPrice { 7 };  //Merchant's wagon parts buying price
	int m_buySuperPillPrice{ 500 };  //Merchant's super pill buying price
	int m_sellFoodPrice{ 8 };	     //Merchant's food selling price
	int m_sellMedicinePrice{ 8 };    //Merchant's medicine selling price
	int m_sellWagonPartsPrice{ 10 }; //Merchant's wagon parts selling price
	int m_sellSuperPillPrice{ 500 }; //Merchant's super pill selling price
public:
	//-------Default Constructor-------//
	/*
		Prices do not have to be set. They will be set when the player
		first interacts with the merchant.
	*/
	Pricing() = default;

	//Randomly resets all buying and selling prices.
	void setRandomPrices();

	//Prints all buying prices. In this case, merchant is buying and player is selling.
	void printBuyingPrices();

	//Prints all selling prices. In this case, merchant is selling and player is buying.
	void printSellingPrices();

	//Passes in a buy or sell choice from the player as well as an item to buy or sell.
	//Retruns the appropriate buying or selling price for that item.
	//NOTE: Should fix this in the future to not use "magic numbers". For now, it will work!
	int getItemPrice(int buyOrSell, int item);
};