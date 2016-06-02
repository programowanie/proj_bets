#include "Race.h"
#include <unistd.h>
#include <iostream>


vector <Horse> Race::vectorOfHorses;
vector <Rider> Race::vectorOfRiders;
vector <int> Race::chances;


Race::Race(int counter): members(counter)
{
}

void Race::init()
{
	Horse *horses = new Horse[members];
	Rider *riders = new Rider[members];

	for(int i = 0; i < members; ++i)
	{
        vectorOfHorses.push_back(horses[i]);
       	vectorOfRiders.push_back(riders[i]);
    }

    delete [] horses;
    delete [] riders;
}

void Race::descriptionOfCompetitors()
{

	cout << "\nW gonitwie wezma udzial:\n";
	usleep(1000000);
	for(int i = 0; i < members; ++i)
	{
	cout << i+1 << ". " << vectorOfRiders[i].name() << " na koniu " << vectorOfHorses[i].name() << endl;
	usleep(1000000);
	}
}

void Race::chanceToGo()
{	
	init();
	
    for(int i = 0; i < members; ++i)
	{
	chances.push_back(vectorOfHorses[i].chances() + vectorOfRiders[i].chances());
	chances[i] = chances[i]/40;
	}
}

void blankLine()
{
	cout.width( 14 );
	cout << right << "||";
	cout.width( 143 ); 
	cout << right << "||\n";
}


void Race::startRace()
{	
	system("clear");
	for(int i = 3; i > 0; --i)
	{
		cout << i << endl;
		usleep(700000);
		system("clear");
	}

	printf("START!\n");

	int k = 1;

	while(*min_element(chances.begin(), chances.end()) < 145)
	{	
		usleep(400000);	//400000
			system("clear");

		blankLine();
	
		for(int i = 0; i < members; ++i) // petla wyswietlajaa jeden ruch
		{
			cout.width( 12 );
			cout << left << vectorOfHorses[i].name() << "||"; // imiona

			chances[i] += rand() % 10;

			if(chances[i] > 140)
			{
				if(!vectorOfHorses[i].score)
				{
					vectorOfHorses[i].score = k;
					vectorOfRiders[i].score = k;
					k++;
					for(int j = 0; j < 140; ++j)  //petla robiaca kreski gdy dojedzie do mety
						cout << left << "=";
					cout << "||" << vectorOfHorses[i].score << endl;
				}
				else
				{
					for(int j = 0; j < 140; ++j)  //petla robiaca kreski gdy jest na mecie
						cout << left << "=";
					cout << "||" << vectorOfHorses[i].score << endl;
				}
			}

			else
			{
				for(int j = 0; j < chances[i]; ++j)  //petla robiaca kreski
					cout << left << "=";
				for(int j = 0; j < 140 - chances[i]; ++j)
					cout << " " ;
				cout << "||\n";
			}

			blankLine();
		}

		cout << "\n\n";

		texts();
		results();
	}

}


void Race::texts()
{
	for(int i = 0; i < members; ++i)
	{
	if(!vectorOfHorses[i].score)
	{
		if(chances[i] == *max_element(chances.begin(), chances.end()))
			cout << vectorOfHorses[i].name() << " jest na prowadzeniu!\n";
		if(chances[i] == *min_element(chances.begin(), chances.end()))
			cout << vectorOfHorses[i].name() << " zostaje w tyle!\n";
	}
	}
}

int Race::getHighScore()
{
	for(int i = 0; i < members; ++i)
	if(vectorOfHorses[i].score == 1)
		return i + 1;
	return 0;
}

void Race::descriptionOfWinner()
{
	cout << "Wygrywa " << vectorOfRiders[getHighScore()-1].name() << " na koniu " << vectorOfHorses[getHighScore()-1].name() << "\n\n";
	cout << vectorOfRiders[getHighScore()-1].description() << endl << vectorOfHorses[getHighScore()-1].description();
}


void Race::results()
{
   for(int i = 0; i < members; ++i)
   {
   		if(vectorOfHorses[i].score)
   		{ 
   			cout << vectorOfHorses[i].name() << " miejsce " << vectorOfHorses[i].score;
			if(vectorOfHorses[i].score == 1)
				cout << " - Gratulujemy! ";
			cout << endl;
		}
	}
}

void Race::clear()
{
	vectorOfHorses.clear();
	vectorOfRiders.clear();
	/*for(int i = 0; i < members; ++i)
	{
		vectorOfHorses[i].score = 0;
		vectorOfRiders[i].score = 0;
	}*/
}

