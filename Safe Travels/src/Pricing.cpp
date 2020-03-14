#include "Pricing.h"

//Randomly resets all buying and selling prices.
void Pricing::setRandomPrices()
{
	m_buyFoodPrice = getRandomNum(10, 20);
	m_buyMedicinePrice = getRandomNum(10, 20);
	m_buyWagonPartsPrice = getRandomNum(10, 20);

	m_sellFoodPrice = getRandomNum(30, 60);
	m_sellMedicinePrice = getRandomNum(30, 60);
	m_sellWagonPartsPrice = getRandomNum(30, 60);
}

//Prints all buying prices. In this case, merchant is buying and player is selling.
void Pricing::printBuyingPrices()
{
	std::cout << "\t\tSelling Prices\n"
		<< "\t  ------------------------\n"
		<< "Food: $" << m_buyFoodPrice << " per lb\n" 
		<< "Medicine: $" << m_buyMedicinePrice << " per pill\n" 
		<< "Wagon Parts: $" << m_buyWagonPartsPrice << " per part\n\n";
}

//Prints all selling prices. In this case, merchant is selling and player is buying.
void Pricing::printSellingPrices()
{
	std::cout << "\t\tBuying Prices\n"
		<< "\t  ------------------------\n"
		<< "Food: $" << m_sellFoodPrice << " per lb\n"
		<< "Medicine: $" << m_sellMedicinePrice << " per pill \n"
		<< "Wagon Parts: $" << m_sellWagonPartsPrice << " per part\n\n";
}

//Passes in a buy or sell choice from the player as well as an item to buy or sell.
//Retruns the appropriate buying or selling price for that item.
int Pricing::getItemPrice(int buyOrSell, int item)
{
	switch (item)
	{
	case(1): //Food
		{
		if (buyOrSell == 1) //Player is buying, merchant is selling
			return m_sellFoodPrice;
		else				//Player is selling, merchant is buying
			return m_buyFoodPrice;
		}
	case(2): //Medicine
		{
			if (buyOrSell == 1) //Player is buying, merchant is selling
				return m_sellMedicinePrice;
			else				//Player is selling, merchant is buying
				return m_buyMedicinePrice;
		}
	case(3): //Wagon Parts
		{
			if (buyOrSell == 1) //Player is buying, merchant is selling
				return m_sellWagonPartsPrice;
			else				//Player is selling, merchant is buying
				return m_buyWagonPartsPrice;
		}
	}
}