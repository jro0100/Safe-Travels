#pragma once
#include <iostream>
#include "Random.h"

class Pricing
{
private:
	int m_buyFoodPrice;		   //Buy food price
	int m_buyMedicinePrice;    //Buy medicine price
	int m_buyWagonPartsPrice;  //Buy wagon parts price
	int m_sellFoodPrice;	   //Sell food price
	int m_sellMedicinePrice;   //Sell medicine price
	int m_sellWagonPartsPrice; //Sell wagon parts price
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
	void getBuyingPrices();

	//Prints all selling prices. In this case, merchant is selling and player is buying.
	void getSellingPrices();

	//Passes in a buy or sell choice from the player as well as an item to buy or sell.
	//Retruns the appropriate buying or selling price for that item.
	//NOTE: Should fix this in the future to not use "magic numbers". For now, it will work!
	int getItemPrice(int buyOrSell, int item);
};