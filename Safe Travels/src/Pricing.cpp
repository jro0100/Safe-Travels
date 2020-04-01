#include "Pricing.h"

//Randomly resets all buying and selling prices.
void Pricing::setRandomPrices()
{
	m_buyFoodPrice = getRandomNum(2, 5);
	m_buyMedicinePrice = getRandomNum(2, 5);
	m_buyWagonPartsPrice = getRandomNum(2, 5);
	m_buySuperPillPrice = getRandomNum(300, 400);

	m_sellFoodPrice = getRandomNum(5, 10);
	m_sellMedicinePrice = getRandomNum(5, 10);
	m_sellWagonPartsPrice = getRandomNum(1, 5);
	m_sellSuperPillPrice = getRandomNum(400, 500);
}

//Prints all buying prices. In this case, merchant is buying and player is selling.
void Pricing::printBuyingPrices()
{
	std::cout << "\t\tSelling Prices\n"
		<< "\t  ------------------------\n"
		<< "\tFood: $" << m_buyFoodPrice << " per lb\n"
		<< "\tMedicine: $" << m_buyMedicinePrice << " per pill\n"
		<< "\tWagon Parts: $" << m_buyWagonPartsPrice << " per part\n"
		<< "\tSuper Pill: $" << m_buySuperPillPrice << " per pill\n\n";
}

//Prints all selling prices. In this case, merchant is selling and player is buying.
void Pricing::printSellingPrices()
{
	std::cout << "\t\tBuying Prices\n"
		<< "\t  ------------------------\n"
		<< "\tFood: $" << m_sellFoodPrice << " per lb\n"
		<< "\tMedicine: $" << m_sellMedicinePrice << " per pill \n"
		<< "\tWagon Parts: $" << m_sellWagonPartsPrice << " per part\n"
		<< "\tSuper Pill: $" << m_sellSuperPillPrice << " per pill\n\n";
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
	case(4): //Super Pill
		{
		if (buyOrSell == 1) //Player is buying, merchant is selling
			return m_sellSuperPillPrice;
		else				//Player is selling, merchant is buying
			return m_buySuperPillPrice;
		}
	}
}