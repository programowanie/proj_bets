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
	speed = randomValuee(20, 90);
	efficiency = randomValuee(20, 90);
	//ability = randomValuee(20, 90);
	//_experience = 0;

}

string Horse::description()
{
	return _name + "\n\tspeed: " + to_string(speed) + " efficiency: " + to_string(efficiency) + "ability: " + to_string(_ability);}
