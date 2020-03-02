#pragma once
#include <string>
#include "Inventory.h"

class Player
{
protected:
	std::string m_name;
	Inventory *const m_inventory;
public:
	//-------Constructor-------//
	Player(const std::string &name, Inventory &inventory) : m_name{ name }, m_inventory{ &inventory }{}
	//-------Virtual Deconstructor------//
	virtual ~Player() {}

	virtual std::string getName() const = 0;
};