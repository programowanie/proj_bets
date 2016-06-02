#include "Horse.h"
#include <stdlib.h>
#include <fstream>

vector <string> Horse::names;

void Horse::init()
{
	ifstream file("horses.txt");
	copy(istream_iterator<string>(file),
		istream_iterator<string>(),
		back_inserter(names));
	file.close();
}

int randomValuee(int a, int b)
{
	return a + rand() % (b-a);	
}

Horse::Horse()
{
	static int amountOfNames = (init(), names.size());
	_name = names[rand() % amountOfNames];
	_speed = randomValuee(10, 90);
	_efficiency = randomValuee(10, 90);
}

int Horse::chances()
{
	return _speed + _efficiency + _ability;
}

string Horse::description()
{
	return _name + "\n\t\tPrędkość: " + to_string(_speed) + " | Sprawnosc " + to_string(_efficiency) + " | Umijetnosci: " + to_string(_ability);}
