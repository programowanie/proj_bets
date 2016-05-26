#pragma once

#include "Competitor.h"
#include <vector>
#include <string>

using namespace std;

class Rider: public Competitor
{
	static vector <string> names;
	string _name;
	int inteligence, slyness;//, ability, _experience;

	static void init();


public:
	Rider();
	string description();
	//int experience() {return _experience;}
	string name() {return _name;}
};