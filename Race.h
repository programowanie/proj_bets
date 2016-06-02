#pragma once

#include "Horse.h"
#include "Rider.h"
#include <vector>

class Race
{
	static vector <Horse> vectorOfHorses;
	static vector <Rider> vectorOfRiders;
	static vector <int> chances;
	void init();
	int members;

public:
	Race(int);

	void chanceToGo();
	void descriptionOfCompetitors();
	void descriptionOfWinner();
	void results();
	void texts();
	void startRace();
	int getHighScore();
	void clear();
};
