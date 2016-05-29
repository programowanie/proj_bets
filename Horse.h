#pragma once

#include "Competitor.h"
#include <vector>
#include <string>

using namespace std;

class Horse: public Competitor
{
	static vector <string> names;
	string _name;
	int _speed, _efficiency;

	static void init();


public:
	Horse();
	int chances();
	string description();
	int speed() {return _speed;}
	int efficiency() {return _efficiency;}
	string name() {return _name;}
};