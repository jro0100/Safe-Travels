#include "Date.h"

//Increases m_week by one
void Date::increaseDate()
{
	//Increment the week count
	if (m_week <= 4)
		m_week++;

	//If the m_week hits five, increment the month and reset m_week to one 
	if (m_week > 4)
	{
		int temp = m_month;
		temp++;
		m_month = static_cast<Month>(temp);

		m_week = 1;
	}

	//If the month of the year exceeds twelve, increment the year and reset the month count
	if (static_cast<int>(m_month) > DECEMBER)
	{
		m_year++;
		m_month = JANUARY;
	}
}

//Returns m_month
std::string Date::getMonth() const
{
	switch (m_month)
	{
	case(JANUARY):
		return "January";
	case(FEBRUARY):
		return "February";
	case(MARCH):
		return "March";
	case(APRIL):
		return "April";
	case(MAY):
		return "May";
	case(JUNE):
		return "June";
	case(JULY):
		return "July";
	case(AUGUST):
		return "August";
	case(SEPTEMBER):
		return "September";
	case(OCTOBER):
		return "October";
	case(NOVEMBER):
		return "November";
	case(DECEMBER):
		return "December";
	default:
		return "???"; //This should never be executed
	}
}

//Overloaded operator<<. Prints the date
std::ostream& operator<<(std::ostream &out, const Date &date)
{
	out << date.getMonth() << " Week: "<< date.m_week << "Year: " << date.m_year;
	return out;
}