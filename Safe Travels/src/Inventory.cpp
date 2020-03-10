#include "Inventory.h"

//-------Food altering functions-----------//
//Changes the food count. This will only be used by the merchant
void Inventory::setFoodCount(int count)
{
	m_foodCount = count;
}

//Increases the food inventory
void Inventory::increaseFood(int count)
{
	m_foodCount += count;
}

//Decreases the food inventory
void Inventory::useFood() { m_foodCount--; }



//---------Medicine altering functions----------//
//Changes the medicine count. This will only be used by the merchant
void Inventory::setMedicineCount(int count)
{
	m_medicineCount = count;
}

	//Increases the medicine inventory
void Inventory::increaseMedicine(int count)
{
	m_medicineCount += count;
}

//Decreases the medicine inventory
void Inventory::useMedicine() { m_medicineCount--; }




//-------Wagon Parts altering functions--------//
//Changes the wagon parts count. This will only be used by the merchant
void Inventory::setWagonPartsCount(int count)
{
	m_wagonPartsCount = count;
}
	//Increases the wagon parts inventory
void Inventory::increaseWagonParts(int count)
{
	m_wagonPartsCount += count;
}

//Decreases the wagon parts inventory
void Inventory::useWagonPart() { m_wagonPartsCount--; }

//-------------Mmeber Variable Getters-----------//
int Inventory::getFoodCount() const { return m_foodCount; }
int Inventory::getMedicineCount() const { return m_medicineCount; }
int Inventory::getWagonPartsCount() const { return m_wagonPartsCount; }