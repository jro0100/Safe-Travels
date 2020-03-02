#pragma once

class Inventory
{
private:
	int m_foodCount;	   //Holds the food supply
	int m_medicineCount;   //Holds the medicine supply
	int m_wagonPartsCount; //Holds the wagon parts supply
public:
	Inventory() : m_foodCount{ 0 }, m_medicineCount{ 1 }, m_wagonPartsCount{ 0 } {}

	//Functions to alter the food
	void increaseFood(int count);
	void useFood(); //m_medicinePartsCount--;

	//Functions to alter the medicine
	void increaseMedicine(int count);
	void useMedicine(); //m_medicinePartsCount--;

	//Functions to alter the wagon parts
	void increaseWagonParts(int count);
	void useWagonPart(); //m_wagonPartsCount--;

	//Function getters
	int getFoodCount() const;
	int getMedicineCount() const;
	int getWagonPartsCount() const;
};