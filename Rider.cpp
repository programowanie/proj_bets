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
	_inteligence = randomValue(10, 60);
	_slyness = randomValue(20, 80);
}

int Rider::chances()
{
	return _inteligence + _slyness + _ability;
}


string Rider::description()
{
	return _name + "\n\tInteligencja: " + to_string(_inteligence) + " | Sprawnosc: " + to_string(_slyness) + " | Umiejetności: " + to_string(_ability);}
