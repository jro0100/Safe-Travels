#pragma once
#include <iostream>
#include "Random.h"

class Pricing
{
private:
	int m_buyFoodPrice{ 5 };		 //Buy food price
	int m_buyMedicinePrice{ 5 };     //Buy medicine price
	int m_buyWagonPartsPrice { 7 };  //Buy wagon parts price
	int m_sellFoodPrice{ 8 };	     //Sell food price
	int m_sellMedicinePrice{ 8 };    //Sell medicine price
	int m_sellWagonPartsPrice{ 10 }; //Sell wagon parts price
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