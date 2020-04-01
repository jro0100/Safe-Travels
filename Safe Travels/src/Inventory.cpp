#include "Inventory.h"

//-------Food altering functions-----------//
//Changes the food count. This will only be used by the merchant
void Inventory::setFoodCount(int count)
{
	m_foodCount = count;
}

//Increases or decreases the food count
void Inventory::changeFoodCount(int count)
{
	m_foodCount += count;

	if (m_foodCount < 0)
		m_foodCount = 0;
}


//---------Medicine altering functions----------//
//Changes the medicine count. This will only be used by the merchant
void Inventory::setMedicineCount(int count)
{
	m_medicineCount = count;
}

//Increases or decreases the medicine count
void Inventory::changeMedicineCount(int count)
{
	m_medicineCount += count;
}

//Uses on medicine pill
void Inventory::useMedicine() 
{ 
	m_medicineCount--; 

	if (m_medicineCount < 0)
		m_medicineCount = 0;
}




//-------Wagon Parts altering functions--------//
//Changes the wagon parts count. This will only be used by the merchant
void Inventory::setWagonPartsCount(int count)
{ 
	m_wagonPartsCount = count; 
}
//Increases or decreases the wagon parts count
void Inventory::changeWagonPartsCount(int count) 
{ 
	m_wagonPartsCount += count; 
}


//-------Super pill altering functions--------//
//Changes the super pill count. This will only be used by the merchant
void Inventory::setSuperPillCount(int count) 
{
	m_superPillCount = count; 
}
//Increases or decreases super pill count
void Inventory::changeSuperPillCount(int count)
{
	m_superPillCount += count;
}

//Uses one super pill
void Inventory::useSuperPill()
{
	m_superPillCount--;
}

//-------------Mmeber Variable Getters-----------//
int Inventory::getFoodCount()	    const { return m_foodCount; }
int Inventory::getMedicineCount()   const { return m_medicineCount; }
int Inventory::getWagonPartsCount() const { return m_wagonPartsCount; }
int Inventory::getSuperPillCount()  const { return m_superPillCount; }