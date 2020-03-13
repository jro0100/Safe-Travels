#include "Merchant.h"

//First function called when the player encounters the merchant.
void Merchant::interactWithMerchant(Inventory &inventory, WagonLeader &wagonLeader)
{
	//Randomly reset the merchants inventory
	setRandomInventory();

	//Randomly reset the merchants pricing
	m_pricing.setRandomPrices();

	while (true)
	{
		int choice{};
		wagonLeader.displayInventory(inventory);
		std::cout << "Merchant: What are yah lookin to do?\n" << "(1) Buy\n(2) Sell\n(3) Exit\n";
		choice = getNumChoice(1, 3); //Call this from the universal validation header
		system("cls");

		if (choice != 3)
			buyOrSellItems(inventory, wagonLeader, static_cast<buyOrSell>(choice)); //If player is buying then merchant is selling
		else
			break;
	}
	std::cout << "\nMerchant: Thank you! Come back soon.\n\nPress any key to continue";
	std::cin.get();
	std::cin.get();
	system("cls");
}

void Merchant::buyOrSellItems(Inventory &inventory, WagonLeader &wagonLeader, buyOrSell buyOrSellChoice)
{
	if (buyOrSellChoice == BUY)
		m_pricing.getSellingPrices();
	else if (buyOrSellChoice == SELL)
		m_pricing.getBuyingPrices();

	wagonLeader.displayInventory(inventory);

	std::cout << "Choose one of the following:\n(1) Food\n(2) Medicine\n(3) Wagon Parts\n(4) Exit\n";

	int choice{};
	choice = getNumChoice(1, 4);

	if (choice != 4)
		makePurchase(inventory, wagonLeader, buyOrSellChoice, static_cast<buySellItems>(choice));

	system("cls");
}

void Merchant::makePurchase(Inventory &inventory, WagonLeader &wagonLeader, buyOrSell buyOrSellChoice, buySellItems item)
{
		std::cout << "Enter the amount:\n";
		int itemQuantity{};
		itemQuantity = getNumChoice(1, 100);

		int purchaseCost = (itemQuantity * m_pricing.getItemPrice(buyOrSellChoice, item));

		bool purchaseFailed = false;

		switch (buyOrSellChoice)
		{
		case(BUY):
			if (purchaseCost <= wagonLeader.getCashOnHand())
			{
				wagonLeader.changeCashOnHand(-purchaseCost);

				switch (item)
				{
				case(FOOD):
					inventory.changeFoodCount(itemQuantity);
					m_inventory.changeFoodCount(-itemQuantity);
					break;
				case(MEDICINE):
					inventory.changeMedicineCount(itemQuantity);
					m_inventory.changeMedicineCount(-itemQuantity);
					break;
				case(WAGON_PARTS):
					inventory.changeWagonPartsCount(itemQuantity);
					m_inventory.changeWagonPartsCount(-itemQuantity);
					break;
				}

			}
			else
				purchaseFailed = true;
			break;
		case(SELL):
			switch (item)
			{
			case(FOOD):
				if (itemQuantity <= inventory.getFoodCount())
				{
					wagonLeader.changeCashOnHand(purchaseCost);
					m_inventory.changeFoodCount(itemQuantity);
					inventory.changeFoodCount(-itemQuantity);
				}
				break;
			case(MEDICINE):
				if (itemQuantity <= inventory.getMedicineCount())
				{
					wagonLeader.changeCashOnHand(purchaseCost);
					m_inventory.changeMedicineCount(itemQuantity);
					inventory.changeMedicineCount(-itemQuantity);
				}
				break;
			case(WAGON_PARTS):
				if (itemQuantity <= inventory.getWagonPartsCount())
				{
					wagonLeader.changeCashOnHand(purchaseCost);
					m_inventory.changeWagonPartsCount(itemQuantity);
					inventory.changeWagonPartsCount(-itemQuantity);
				}
				break;
			default:
				purchaseFailed = true;
			}
		}

		if (purchaseFailed)
			std::cout << "\nError - Insufficient Funds\n";
		else
			std::cout << "\nPurchase Successful\n";

		std::cout << "Press any key to continue";
		std::cin.get();
		std::cin.get();
		system("cls");
}

void Merchant::setRandomInventory()
{
	m_inventory.setFoodCount(getRandomNum(0, 100));
	m_inventory.setMedicineCount(getRandomNum(0, 40));
    m_inventory.setWagonPartsCount(getRandomNum(0, 20));
}