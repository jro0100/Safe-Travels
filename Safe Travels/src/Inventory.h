#pragma once

class Inventory
{
private:
	int m_foodCount;	   //Holds the food supply
	int m_medicineCount;   //Holds the medicine supply
	int m_wagonPartsCount; //Holds the wagon parts supply
	int m_superPillCount;  //Holds the super pill supply
public:
	//---Constructor--- used with the Player class
	Inventory() : m_foodCount{ 0 }, m_medicineCount{ 0 }, m_wagonPartsCount{ 0 }, m_superPillCount{ 0 } {}
	//---Constructor--- used for the Merchant class
	Inventory(int foodCount, int medicineCount, int wagonPartsCount, int superPillsCount) 
		: m_foodCount{ foodCount }, m_medicineCount{ medicineCount }, 
		  m_wagonPartsCount{ wagonPartsCount }, m_superPillCount{ superPillsCount } {}

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

	//Functions to alter the wagon parts
	void setSuperPillCount(int count); //Used only by the merchant
	void changeSuperPillCount(int count);
	void useSuperPill(); //m_superPillCount--;

	//Function getters
	int getFoodCount() const;
	int getMedicineCount() const;
	int getWagonPartsCount() const;
	int getSuperPillCount() const;
};