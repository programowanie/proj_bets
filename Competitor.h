#pragma once

#include <string>
#include <vector>

using namespace std;

class Competitor
{

protected:
	int _ability, _experience;
	
public:
	Competitor();
	int score;
	int experience() {return _experience;}
	int ability() {return _ability;}
	int upgradeExperience(int*);
	virtual std::string description() = 0;
	virtual int chances() = 0;
};