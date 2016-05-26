#pragma once

#include "Competitor.h"
#include <vector>
#include <string>

using namespace std;

class Horse: public Competitor
{
	static vector <string> names;
	string _name;
	int speed, efficiency;//, ability, _experience;

	static void init();


public:
	Horse();
	string description();
	//int experience() {return _experience;}
	string name() {return _name;}
};