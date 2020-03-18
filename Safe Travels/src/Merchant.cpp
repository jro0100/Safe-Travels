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
		m_pricing.printSellingPrices(); //Display the merchant's selling prices/player's buying prices
		printMerchantsInventory(); //This lets the player know that they can only buy so much from the merchant
		break;
	case(SELL):
		m_pricing.printBuyingPrices(); //Display the merchant's buying prices/player's selling prices
		break;
	}

	wagonLeader.displayInventory(inventory); //Display the player's inventory

	std::cout << "Choose one of the following:\n(1) Food\n(2) Medicine\n(3) Wagon Parts\n(4) Exit\n";

	//Gets and validates a number between 1 and 4 from the player and casts it to an enum
	buySellItems choice = static_cast<buySellItems>(getNumChoice(1, 4));

	if (choice != EXIT) //if the player does choose to exit
		//Do the backend work of buying or selling. This includes the validation of making sure
		//there is enough cash when player is buying, enough inventory when player is selling, etc.
		makePurchase(inventory, wagonLeader, buyOrSellChoice, static_cast<buySellItems>(choice));

	system("cls"); //Clear the screen
}

/*
	This is where all of the backend work of buying and selling take place. The only interaction with the player
	is asking for the amount to either buy or sell.

	When buying, this member function will:
		1.) Check if the player has enough cash to complete the transaction.
		2.) Check if the merchant has enough inventory to complete the transaction.
		3.) If either of the above fail, then the bool purchaseFailed will be set to true and an error message will print.
		4.) If neither fail, the newly bought item amount will be added to the player's inventory, that same amount will
			be subtracted from the merchant's inventory, and the purchaseCost will be subtracted from the player's cashOnHand.

	When selling, this member function will:
		1.) Check if the player has enough of that item to sell.
		2.) If the above fails, then the bool purchaseFailed will be set to true and an error message will print.


*/
void Merchant::makePurchase(Inventory &inventory, WagonLeader &wagonLeader, buyOrSell buyOrSellChoice, buySellItems item)
{
		//Interact with the player to get the amount they would like to buy or sell of the item
		std::cout << "Enter the amount:\n";
		int itemQuantity{};
		//Gets and validates a number between 1 and 100 from the player. This is the item amount to either buy or sell
		itemQuantity = getNumChoice(1, 100);

		//Calculate how much the items are worth based on the quantity and current price being offered by the merchant
		int purchaseCost = (itemQuantity * m_pricing.getItemPrice(buyOrSellChoice, item));

		//Used to tell whether the transaction fails when buying or selling
		bool purchaseFailed = false;

		/*
			Switch statement is split into two cases: case(BUY) and case(SELL)
			
			Each case is split up into another switch statement which handles what 
			to do for each different item being bought or sold. 
			The cases are: case(FOOD), case(MEDICINE), and case(WAGON_PARTS)

		*/
		switch (buyOrSellChoice)
		{
		//Handles what happens when the player is buying an item
		case(BUY):
			//Checks to make sure the cost of the item being bought does not exceed the player's cashOnHand
			if (purchaseCost <= wagonLeader.getCashOnHand())
			{
				//Split up to handle each case of the player buying a different item. 
				//NOTE: The player may only buy one item at a time.
				switch (item)
				{
				case(FOOD):
					//If the amount being bought is less than or equal to the merchant's food on hand, 
					//then continue with the purchase
					if (itemQuantity <= m_inventory.getFoodCount())
					{
						//Add certain amount food to the player's inventory
						inventory.changeFoodCount(itemQuantity);
						//Subtract that same certain amount of food from the merchant's inventory
						m_inventory.changeFoodCount(-itemQuantity);
					}
					//Otherwise, the purchase has failed
					else
						purchaseFailed = true;
					break;
					//If the amount being bought is less than or equal to the merchant's medicine on hand, 
					//then continue with the purchase
				case(MEDICINE):
					if (itemQuantity <= m_inventory.getMedicineCount())
					{
						//Add certain amount medicine to the player's inventory
						inventory.changeMedicineCount(itemQuantity);
						//Subtract that same certain medicine of food from the merchant's inventory
						m_inventory.changeMedicineCount(-itemQuantity);
					}
					//Otherwise, the purchase has failed
					else
						purchaseFailed = true;
					break;
					//If the amount being bought is less than or equal to the merchant's wagon parts on hand, 
					//then continue with the purchase
				case(WAGON_PARTS):
					if (itemQuantity <= m_inventory.getWagonPartsCount())
					{
						//Add certain amount wagon parts to the player's inventory
						inventory.changeWagonPartsCount(itemQuantity);
						//Subtract that same certain wagon parts of food from the merchant's inventory
						m_inventory.changeWagonPartsCount(-itemQuantity);
					}
					//Otherwise, the purchase has failed
					else
						purchaseFailed = true;
					break;
				}
				//The transaction has to have succeeded(purchaseFailed = false) if this is being run.
				//Complete the purchase by taking the cash from the player.
				wagonLeader.changeCashOnHand(-purchaseCost);
			}
			//Otherwise, the cost of the item being bought did exceed the player's cashOnHand, and the purchase fails
			else
				purchaseFailed = true;
			break;

		//Handles what happens when the player is selling an item
		case(SELL):

			//Split up each case of the player selling a different item. 
			//NOTE: The player may only sell one item at a time.
			switch (item)
			{
			case(FOOD):
				//If the amount of food being sold does not exceed the amount the player has on hand,
				//then continue with the transaction
				if (itemQuantity <= inventory.getFoodCount())
				{
					//Give the cash to the player
					wagonLeader.changeCashOnHand(purchaseCost);
					//Give the food to the merchant
					m_inventory.changeFoodCount(itemQuantity);
					//Take the food from the player
					inventory.changeFoodCount(-itemQuantity);
				}
				//Otherwise, the transaction has failed
				else
					purchaseFailed = true;
				break;
			case(MEDICINE):
				//If the amount of medicine being sold does not exceed the amount the player has on hand,
				//then continue with the transaction
				if (itemQuantity <= inventory.getMedicineCount())
				{
					//Give the cash to the player
					wagonLeader.changeCashOnHand(purchaseCost);
					//Give the medicine to the merchant
					m_inventory.changeMedicineCount(itemQuantity);
					//Take the medicine from the player
					inventory.changeMedicineCount(-itemQuantity);
				}
				//Otherwise, the transaction has failed
				else
					purchaseFailed = true;
				break;
			case(WAGON_PARTS):
				//If the amount of wagon parts being sold does not exceed the amount the player has on hand,
				//then continue with the transaction
				if (itemQuantity <= inventory.getWagonPartsCount())
				{
					//Give the cash to the player
					wagonLeader.changeCashOnHand(purchaseCost);
					//Give the wagon parts to the merchant
					m_inventory.changeWagonPartsCount(itemQuantity);
					//Take the wagon parts from the player
					inventory.changeWagonPartsCount(-itemQuantity);
				}
				//Otherwise, the transaction has failed
				else
					purchaseFailed = true;
				break;
			}
		}

		//Prints the error message if the transaction has failed
		if (purchaseFailed)
			std::cout << "\n*Error - Transaction Failed due to insufficient numbers*\n";
		//Otherwise, the transaction never failed and must have succeeded
		else
			std::cout << "\nPurchase Successful\n";

		//Pause for the user to read
		std::cout << "Press any key to continue";
		std::cin.get();
		std::cin.get();
		system("cls"); //Clear the screen
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