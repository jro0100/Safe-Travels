#include "Validation.h"

//Prompts the player for yes or no input and then validates that input before returning it.
char getYesNoChoice()
{
	char yesOrNoChoice{};

	//Continously loops until the player enters valid input (Y,y,N,n)
	while (true)
	{
		std::cout << "Choice (Y/N) --> ";
		std::cin >> yesOrNoChoice;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
		else if (yesOrNoChoice == 'Y' || yesOrNoChoice == 'y' || yesOrNoChoice == 'N' || yesOrNoChoice == 'n')
			return toupper(yesOrNoChoice); //Force the character to uppercase before returning it.

		std::cout << "Error - Try again\n";
	}
}

//Validates the choice entered by the player on the start menu.
//Only valid choices are 1(start the game), 2(Display the rules), and 3(About the game)
int getNumChoice(int min, int max)
{
	int choice{ 0 };

	std::vector<int> possibleChoices;
		for (int i = 0; i < (max - min + 1); i++)
			possibleChoices.push_back(min + i);

	//Continuously loops until the entry is an integer between 1 and 3 inclusively
	while (true)
	{
		std::cout << "Choice --> ";
		std::cin >> choice;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
		else
		{
			for (int i = 0; i < (max - min + 1); i++)
				if (choice == possibleChoices[i])
					return choice;
		}
		std::cout << "Error - Try again\n";
	}
}