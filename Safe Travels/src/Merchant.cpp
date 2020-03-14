#include "Merchant.h"

//First function called when the player encounters the merchant.
void Merchant::interactWithMerchant(const Journey &journey, Inventory &inventory, WagonLeader &wagonLeader)
{
	//Gets compared to actual miles travelled by the player to determine if the player has moved since last
	//visiting the merchant.
	static int milesTravelled = { -1 };

	/*
		Without the below if statement comparison, the user would be able to keep visiting the merchant 
		and the merchant's pricing will change each time without the player having to travel

		How it Works: If the static variable "milesTravelled" is not equal to the actual miles travelled
					  by the player, then that means the player has moved. It then randomly resets the
					  merchant's pricing and inventory and then sets the milesTravelled variable to the
					  actual miles travelled. Now if the player exits interacting with the merchant and
					  returns, this block will not be run, therefore, not running the random reset functions
					  and not changing the anything.
	*/
	if (milesTravelled != journey.getMilesTravelled())
	{
		//Randomly reset the merchants inventory
		setRandomInventory();

		//Randomly reset the merchants pricing
		m_pricing.setRandomPrices();

		//Set the static variable to the actual miles travelled so if the player comes back without travelling,
		//this if block will not be executed and the merchant's prices and inventory will not change.
		milesTravelled = journey.getMilesTravelled();
	}

	while (true)
	{
		//Display the player's inventory
		wagonLeader.displayInventory(inventory);

		std::cout << "Merchant: What are yah lookin to do?\n" << "(1) Buy\n(2) Sell\n(3) Exit\n";

		//Call getNumChoice from the Validation.h file. This will return a number between 1 and 3.
		int choice{};
		choice = getNumChoice(1, 3);
		
		system("cls");

		//When choice = 3, the player has chose to exit the interaction
		if (choice != 3)
			//Call function to initiate the buying/selling
			buyOrSellItems(inventory, wagonLeader, static_cast<buyOrSell>(choice)); //If player is buying then merchant is selling
		else
			break; //This will cause the loop to terminate, ending the interaction with the merchant
	}
	//At this point, the user has chosen to exit interaction with the merchant. 
	std::cout << "\nMerchant: Thank you! Come back soon.\n\nPress any key to continue";
	std::cin.get();
	std::cin.get();
	system("cls");
}

//This member function is called from the interactWithMerchant function.
//It is called when the player has chosen to either buy from or sell to the merchant.
void Merchant::buyOrSellItems(Inventory &inventory, WagonLeader &wagonLeader, buyOrSell buyOrSellChoice)
{
	switch (buyOrSellChoice)
	{
	case(BUY):
		m_pricing.printSellingPrices();
		printMerchantsInventory();
		break;
	case(SELL):
		m_pricing.printBuyingPrices();
		break;
	}

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
				switch (item)
				{
				case(FOOD):
					if (itemQuantity > m_inventory.getFoodCount())
					{
						purchaseFailed = true;
						break;
					}
					inventory.changeFoodCount(itemQuantity);
					m_inventory.changeFoodCount(-itemQuantity);
					break;
				case(MEDICINE):
					if (itemQuantity > m_inventory.getMedicineCount())
					{
						purchaseFailed = true;
						break;
					}
					inventory.changeMedicineCount(itemQuantity);
					m_inventory.changeMedicineCount(-itemQuantity);
					break;
				case(WAGON_PARTS):
					if (itemQuantity > m_inventory.getWagonPartsCount())
					{
						purchaseFailed = true;
						break;
					}
					inventory.changeWagonPartsCount(itemQuantity);
					m_inventory.changeWagonPartsCount(-itemQuantity);
					break;
				}
				wagonLeader.changeCashOnHand(-purchaseCost);
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
			std::cout << "\nError - Insufficient Purchase\n";
		else
			std::cout << "\nPurchase Successful\n";

		std::cout << "Press any key to continue";
		std::cin.get();
		std::cin.get();
		system("cls");
}

//Prints the merchant's inventory to the screen
void Merchant::printMerchantsInventory()
{
	std::cout << "\t\tMerchants Inventory\n"
		<< "\t  ---------------------------\n"
		<< "Food: " << m_inventory.getFoodCount() << " lb(s)\n"
		<< "Medicine: " << m_inventory.getMedicineCount() << " pill(s) \n"
		<< "Wagon Parts: " << m_inventory.getWagonPartsCount() << " part(s)\n\n";
}

//Randomly resets the merchants inventory. This simulates a different merchant at each stop
void Merchant::setRandomInventory()
{
	m_inventory.setFoodCount(getRandomNum(0, 15));
	m_inventory.setMedicineCount(getRandomNum(0, 8));
    m_inventory.setWagonPartsCount(getRandomNum(0, 20));
}