#pragma once
#include <iostream>
#include <string>

class Date
{
public:
	//Keeps track of the months
	enum Month
	{
		JANUARY,
		FEBRUARY,
		MARCH,
		APRIL,
		MAY,
		JUNE,
		JULY,
		AUGUST,
		SEPTEMBER,
		OCTOBER,
		NOVEMBER,
		DECEMBER
	};
private:
	Month m_month; //Month
	int m_week;	   //Day
	int m_year;	   //Year
public:
	//-------Constructor-------//
	Date() : m_month{ APRIL }, m_week{ 1 }, m_year{ 1808 } {} //Game begins on April 1st, 1808

	void increaseDate();

	std::string getMonth() const;
	friend std::ostream& operator<<(std::ostream &out, const Date &date);
};