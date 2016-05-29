#pragma once

#include "Horse.h"
#include "Rider.h"
#include <vector>

class Race
{
	static vector <Horse> vectorOfHorses;
	static vector <Rider> vectorOfRiders;
	static vector <int> chances;

public:
	Race();
	void init();
	void chanceToGo();
	void descriptionOfCompetitors();
	void results();

	void startRace();

};
