#include "Rider.h"
#include <stdlib.h>
#include <fstream>

vector <string> Rider::names;

void Rider::init()
{
	ifstream file("riders.txt");
	copy(istream_iterator<string>(file),
		istream_iterator<string>(),
		back_inserter(names));
	file.close();
}

int randomValue(int a, int b)
{
	return a + rand() % (b-a);	
}

Rider::Rider()
{
	static int amountOfNames = (init(), names.size());
	_name = names[rand() % amountOfNames];
	inteligence = randomValue(10, 50);
	slyness = randomValue(20, 80);
	//ability = randomValue(20, 90);
	//_experience = 0;

}

string Rider::description()
{
	return _name + "\n\tinteligence: " + to_string(inteligence) + " efficiency: " + to_string(slyness);}
