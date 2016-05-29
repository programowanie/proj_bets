#pragma once

#include "Competitor.h"
#include <vector>
#include <string>

using namespace std;

class Rider: public Competitor
{
	static vector <string> names;
	string _name;
	int _inteligence, _slyness;

	static void init();


public:
	Rider();
	int chances();
	string description();
	int inteligence() {return _inteligence;}
	int slyness(){return _slyness;}
	string name() {return _name;}
};