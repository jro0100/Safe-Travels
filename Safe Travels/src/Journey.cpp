#include "Journey.h"

//Increase the miles travelled
//Pass in a random number between 10 and 100 miles
void Journey::increaseMilesTravelled(int miles)
{
	//Increase total miles travelled in the game
	m_totalMilesTravelled += miles;

	//Don't allow the player to travel past the end of the game
	if (m_totalMilesTravelled > TOTAL_GAME_MILES)
		m_totalMilesTravelled = TOTAL_GAME_MILES;

	//Decrease miles left until the end of the game
	m_milesRemaining -= miles;

	//Don't allow the player to travel past the end of the game
	if (m_milesRemaining < 0)
		m_milesRemaining = 0;

	//Decrease miles left until next destination
	m_milesToNextDest -= miles;

	//Don't allow the player to travel past the destination without having the option to stop
	if (m_milesToNextDest < 0)
		m_milesToNextDest = 100;
}