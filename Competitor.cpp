#include "Competitor.h"
#include <cstdlib>

Competitor::Competitor()
{
	_ability = 20 + rand() % 75;
	_experience = 0;
}