#include "Competitor.h"
#include <cstdlib>

Competitor::Competitor()
{
	_ability = 10 + rand() % 75;
	_experience = 0;
	score = 0;
}

int Competitor::upgradeExperience(int* a)
{
	return _experience += *a;
}