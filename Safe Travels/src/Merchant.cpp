#include "Merchant.h"


void Merchant::interactWithMerchant(WagonLeader &wagonLeader)
{
		setRandomInventory();
		//m_pricing.setRandomPrices();

		while(true)
		{
			int choice{};
			std::cout << "Merchant: What are yah lookin to do?\n\n" << "(1) Buy\n(2) Sell\n(3) Exit\n";
			//getChoice(); //Call this from the universal validation header

			if(choice == 1)
			{
				//m_pricing.getBuyingPrices(); //Called from the pricing class
				//buyItem(wagonLeader); //will call m_pricing.getBuyingPrices() and then use the getChoice function to validate
			}
			else if(choice == 2)
			{
				//m_pricing.getSellingPrices(); //Called from the Pricing class
				//sellItem(wagonLeader); //will call m_pricing.getSellingPrices() and then use the getChoice function to validate
			}
			else
				break;
		}
		std::cout << "Thank you! Come back soon.\n";
}

void Merchant::setRandomInventory()
{
	//m_inventory.setFoodCount(getRandomNum(0, 100));
	//m_inventory.setMedicineCount(getRandomNum(0, 40));
    // m_inventory.setWagonPartsCount(getRandomNum(0, 20));
}