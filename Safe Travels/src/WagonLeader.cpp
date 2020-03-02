#include "WagonLeader.h"

//Alters the cash on hand that the wagon leader has
void WagonLeader::changeCashOnHand(int cash)
{
	m_cashOnHand += cash;
}

//Getter - returns the current cash on hand
int WagonLeader::getCashOnHand() const { return m_cashOnHand; }