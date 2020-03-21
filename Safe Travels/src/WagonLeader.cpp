#include "WagonLeader.h"

//Alters the cash on hand that the wagon leader has
void WagonLeader::changeCashOnHand(int cash)
{
	m_cashOnHand += cash;
}

//Getter - returns the current cash on hand
int WagonLeader::getCashOnHand() const { return m_cashOnHand; }


//Displays the current inventory.
void WagonLeader::displayInventory(const Inventory &inventory) const
{
	std::cout << "\t\tYour Inventory\n"
		<< "\t-----------------------------\n"
		<< "Food: " << inventory.getFoodCount() << " lbs\n"
		<< "Medicine: " << inventory.getMedicineCount() << " pills\n"
		<< "Wagon Parts: " << inventory.getWagonPartsCount() << " parts\n"
		<< "Cash On Hand: $" << getCashOnHand() << "\n\n";
}