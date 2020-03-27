//-------------------SAFE TRAVELS------------------//

//Game designed on 2/29/2020
//Coding began on 3/1/2020

#include "Game.h"

int main()
{

	Game game;
	game.flow();
}

/*
	TODO:

	Having problems with deep copying the inventory pointer (using overloaded assingment operator). 
	Need to work on this in FamilyMember.h.

	Two options for implemenation in deleting a familyMember from the vector:

	1.) Design my own function
		
		void deleteMember(std::vector<FamilyMember> &familyMember, int deleteAtIndex)
		{
			std::vector<FamilyMember> newFamilyMember{};
			for (int i = 0; i < familyMember.size(); i++)
			{
				if (i != deleteAtIndex)
					newFamilyMember.push_back(familyMember[i]);
			}
	
			familyMember = newFamilyMember;
		}

	2.) Use the std::vector's erase member function. Not sure how affetive this will be. Have to test it.
	
		familyMember.erase(familyMember.begin() + 1);

*/