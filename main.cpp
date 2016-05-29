#include "Horse.h"
#include "Rider.h"
#include "Race.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	
	Race wyscig;
	wyscig.init();
	wyscig.chanceToGo();
	wyscig.descriptionOfCompetitors();
	wyscig.startRace();
	wyscig.results();
}