#include "WagonLeader.h"

//Alters the cash on hand that the wagon leader has
void WagonLeader::changeCashOnHand(int cash)
{
	m_cashOnHand += cash;
}

//Getter - returns the current cash on hand
int WagonLeader::getCashOnHand() const { return m_cashOnHand; }


//Displays the current inventory.
void WagonLeader::displayInventory(const Inventory &inventory)
{
	std::cout << "\t\tYour Inventory\n"
		<< "\t--------------------------------\n"
		<< "Cash On Hand --> " << getCashOnHand() << "\n"
		<< "Food(lbs) --> " << inventory.getFoodCount() << "\n"
		<< "Medicine  --> " << inventory.getMedicineCount() << "\n"
		<< "Wagon Parts --> " << inventory.getWagonPartsCount() << "\n\n";

//	std::cout << "Press Any Key to Return";
//	std::cin.ignore(32767, '\n');
//	std::cin.get();
//	system("cls");
}