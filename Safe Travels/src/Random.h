#pragma once
#include <cstdlib>
#include <ctime>

int getRandomNum(int min, int max)
{
	if (min > max)
		return 0;
	return rand() % (max + 1 - min) + min;
}