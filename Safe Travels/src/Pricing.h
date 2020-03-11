#pragma once
#include <iostream>
#include "Random.h"

class Pricing
{
private:
	int m_buyFoodPrice;
	int m_buyMedicinePrice;
	int m_buyWagonPartsPrice;
	int m_sellFoodPrice;
	int m_sellMedicinePrice;
	int m_sellWagonPartsPrice;
public:
	Pricing() : m_buyFoodPrice{ 100 }, m_buyMedicinePrice{ 100 }, m_buyWagonPartsPrice{ 100 },
		m_sellFoodPrice{ 100 }, m_sellMedicinePrice{ 100 }, m_sellWagonPartsPrice{ 100 } {}

	void setRandomPrices();
	void getBuyingPrices();
	void getSellingPrices();
};