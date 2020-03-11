#pragma once
#include <iostream>
#include <vector>

//Prompts the player for yes or no input and then validates that input before returning it.
char getYesNoChoice();

//Validates the choice entered by the player on the start menu.
//Only valid choices are 1(start the game), 2(Display the rules), and 3(About the game)
int getNumChoice(int min, int max);