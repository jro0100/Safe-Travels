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
		<< "\tFood: " << inventory.getFoodCount() << " lbs\n"
		<< "\tMedicine: " << inventory.getMedicineCount() << " pills\n"
		<< "\tWagon Parts: " << inventory.getWagonPartsCount() << " parts\n"
		<< "\tSuper Pills: " << inventory.getSuperPillCount() << " pills\n"
		<< "\tCash on Hand: $" << getCashOnHand() << "\n\n";
}