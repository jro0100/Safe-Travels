#include "Merchant.h"

void Merchant::buyItems(Inventory &inventory, WagonLeader &wagonLeader)
{
	wagonLeader.displayInventory(inventory);
	std::cin.get();
	std::cin.get();
}

void Merchant::sellItems(Inventory &inventory, WagonLeader &wagonLeader)
{
	wagonLeader.displayInventory(inventory);
	std::cin.get();
	std::cin.get();
}

void Merchant::interactWithMerchant(Inventory &inventory, WagonLeader &wagonLeader)
{
		setRandomInventory();
		m_pricing.setRandomPrices();

		while(true)
		{
			int choice{};
			std::cout << "Merchant: What are yah lookin to do?\n\n" << "(1) Buy\n(2) Sell\n(3) Exit\n";
			getNumChoice(1, 3); //Call this from the universal validation header

			if(choice == 1)
			{
				m_pricing.getBuyingPrices();
				sellItems(inventory, wagonLeader); //If player is buying then merchant is selling
			}
			else if(choice == 2)
			{
				m_pricing.getSellingPrices();
				buyItems(inventory, wagonLeader); //If player is selling then merchant is buying
			}
			else
				break;
		}
		std::cout << "Thank you! Come back soon.\n";
		system("cls");
}

void Merchant::setRandomInventory()
{
	m_inventory.setFoodCount(getRandomNum(0, 100));
	m_inventory.setMedicineCount(getRandomNum(0, 40));
    m_inventory.setWagonPartsCount(getRandomNum(0, 20));
}