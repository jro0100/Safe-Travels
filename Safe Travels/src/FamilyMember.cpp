#include "FamilyMember.h"

//Makes the Family Member sick. If the family member is already sick, they get sicker
void FamilyMember::aquireSickness()
{
	changeSickness(getRandomNum(0, 2));
}

//Decreases the family member's sickweight
void FamilyMember::changeSickness(int sickWeight)
{
	m_sickWeight += sickWeight;

	//Sick weight maxes out at 5
	if (m_sickWeight > 5)
		m_sickWeight = 5;

	//Sick weight can not go below 0
	if (m_sickWeight < 0)
		m_sickWeight = 0;
}

//Makes the family member less sick. Uses medicine from the inventory
void FamilyMember::getBetter()
{
	if (m_sickWeight > 0)
	{
		if (m_inventory->getMedicineCount() > 0)
		{
			m_inventory->useMedicine();
			m_sickWeight--;
			m_health++;
			decreaseAppetite();
		}
	}

	if (m_health > 100)
		m_health = 100;
}

//Checks if the family member has died
bool FamilyMember::isDead() const
{
	return (m_health <= 0);
}

//Increases the appetite of the family member
void FamilyMember::increaseAppetite()
{
	m_appetite += m_sickWeight;

	if (m_appetite > 10)
		m_appetite = 10;
}

//Decreases the appetite of the family member
void FamilyMember::decreaseAppetite()
{
	m_appetite--;

	if (m_appetite < 2)
		m_appetite = 2;
}

//Decreases the family member's health
void FamilyMember::decreaseHealth()
{
	m_health -= m_sickWeight;

	if (m_inventory->getFoodCount() <= 0)
		m_health -= m_appetite;

	if (m_health < 0)
		m_health = 0;
}

//Increases the family member's health
void FamilyMember::changeHealth(int health)
{
	m_health += health;

	if (m_health > 100)
		m_health = 100;
}

void FamilyMember::runThroughRound()
{
	aquireSickness();
	getBetter();
	increaseAppetite();
	decreaseHealth();
}