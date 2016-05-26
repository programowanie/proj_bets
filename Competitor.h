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
	int experience() {return _experience;}
	int ability() {return _ability;}
	virtual std::string description() = 0;
};