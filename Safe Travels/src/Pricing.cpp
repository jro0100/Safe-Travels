#include "Pricing.h"

void Pricing::setRandomPrices()
{
	m_buyFoodPrice = getRandomNum(10, 20);
	m_buyMedicinePrice = getRandomNum(10, 20);
	m_buyWagonPartsPrice = getRandomNum(10, 20);

	m_sellFoodPrice = getRandomNum(30, 60);
	m_sellMedicinePrice = getRandomNum(30, 60);
	m_sellWagonPartsPrice = getRandomNum(30, 60);
}

void Pricing::getBuyingPrices()
{
	std::cout << "Food: $" << m_buyFoodPrice << " per lb\n" <<
		"Medicine: $" << m_buyMedicinePrice << " each " <<
		"Wagon Parts: $" << m_buyWagonPartsPrice << " each\n";
}

void Pricing::getSellingPrices()
{
	std::cout << "Food: $" << m_sellFoodPrice << " per lb\n" <<
		"Medicine: $" << m_sellMedicinePrice << " each " <<
		"Wagon Parts: $" << m_sellWagonPartsPrice << " each\n";
}