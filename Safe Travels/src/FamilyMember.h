#pragma once
#include "Player.h"

class FamilyMember final : public Player
{
private:
	int m_health;	  //Holds the health of the Family Member (Max is 100)
	int m_sickWeight; //Holds how sick the Family Member is (Larger sickWeight = sicker they are)
	int m_appetite;	  //Holds the appetite of the Family Member (Larger appetite = more food they consume)
public:
	//--------Constructor--------//
	FamilyMember(const std::string &name, Inventory &inventory)
		: Player{ name, inventory }, m_health{ 100 }, m_sickWeight{ 0 }, m_appetite{ 2 } {}

	//-------------Altering Functions----------//
	//Makes the Family Member sick. If the family member is already sick, they get sicker
	void aquireSickness();

	//Makes the family member less sick. Uses medicine from the inventory
	void getBetter();

	//Checks if the family member has died
	bool isDead() const;

	//Increases the appetite of the family member
	void increaseAppetite();

	//Decreases the appetite of the family member
	void decreaseAppetite();

	//Decreases the family member's health
	void decreaseHealth(int count);

	//------------Function Member Getters-----------//
	int getSickWeight() const { return m_sickWeight; }
	int getHealth()     const { return m_health; }
	int getAppetite()   const { return m_appetite; }

	//Return the name of the Family Member//
	virtual std::string getName() const final override { return m_name; }
};