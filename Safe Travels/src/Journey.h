#pragma once

class Journey
{
private:
	const int TOTAL_GAME_MILES{ 3000 }; //Total Miles in the game
	int m_totalMilesTravelled;			//Miles travelled since the start of the game
	int m_milesRemaining;				//Miles remaining until the end of the game
	int m_milesToNextDest;				//Miles remaining until the next destinationis reached
public:
	//---------Constructor--------//
	Journey() :m_totalMilesTravelled{ 0 }, m_milesRemaining{ TOTAL_GAME_MILES }, m_milesToNextDest{ 100 } {}

	//Increases the miles travelled for the week
	void increaseMilesTravelled(int miles);

	//----------Member Function Getters---------//
	int getMilesTravelled()  const { return m_totalMilesTravelled; }
	int getMilesRemaining()  const { return m_milesRemaining; }
	int getMilesToNextDest() const { return m_milesToNextDest; }
};