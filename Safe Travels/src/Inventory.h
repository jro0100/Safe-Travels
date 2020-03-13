#pragma once

class Inventory
{
private:
	int m_foodCount;	   //Holds the food supply
	int m_medicineCount;   //Holds the medicine supply
	int m_wagonPartsCount; //Holds the wagon parts supply
public:
	//---Constructor--- used with the Player class
	Inventory() : m_foodCount{ 0 }, m_medicineCount{ 1 }, m_wagonPartsCount{ 0 } {}
	//---Constructor--- used for the Merchant class
	Inventory(int foodCount, int medicineCount, int wagonPartsCount) 
		: m_foodCount{ foodCount }, m_medicineCount{ medicineCount }, m_wagonPartsCount{ wagonPartsCount } {}

	//Functions to alter the food
	void setFoodCount(int count); //Used only by the merchant
	void changeFoodCount(int count);
	void useFood(); //m_medicinePartsCount--;

	//Functions to alter the medicine
	void setMedicineCount(int count); //Used only by the merchant
	void changeMedicineCount(int count);
	void useMedicine(); //m_medicinePartsCount--;

	//Functions to alter the wagon parts
	void setWagonPartsCount(int count); //Used only by the merchant
	void changeWagonPartsCount(int count);
	void useWagonPart(); //m_wagonPartsCount--;

	//Function getters
	int getFoodCount() const;
	int getMedicineCount() const;
	int getWagonPartsCount() const;
};