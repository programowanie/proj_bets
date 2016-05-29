#include "Race.h"
#include <time.h>
#include <iostream>


vector <Horse> Race::vectorOfHorses;
vector <Rider> Race::vectorOfRiders;
vector <int> Race::chances;


Race::Race()
{
}

void Race::init()
{
	Horse horses[8];
	Rider riders[8];

	for(int i = 0; i < 8; ++i)
	{
        vectorOfHorses.push_back(horses[i]);
       	vectorOfRiders.push_back(riders[i]);
    }
}

void Race::descriptionOfCompetitors()
{
	cout << "W gonitwie wezma udzial:\n";
	for(int i = 0; i < 8; ++i)
	{
	cout << i+1 << ". " << vectorOfRiders[i].name() << " na koniu " << vectorOfHorses[i].name() << endl;
	usleep(1000000);
	}
}

void Race::chanceToGo()
{
    for(int i = 0; i < 8; ++i)
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


	int uncertain = 0;
	int k = 1;

	while(*min_element(chances.begin(), chances.end()) < 140)
	{	
		usleep(350000);	//400000
			system("clear");

		blankLine();
	
		for(int i = 0; i < 8; ++i) // petla wyswietlajaa jeden ruch
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
					for(int j = 0; j < 140; ++j)  //petla robiaca kreski gdy dojedzie do mety
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
	}
}

void Race::results()
{
 
   for(int i = 0; i < 8; ++i)
   { 
   		cout << vectorOfHorses[i].name() << " miejsce " << vectorOfHorses[i].score;
		if(vectorOfHorses[i].score == 1)
			cout << " - Gratulujemy! ";
		cout << endl;
	}
}




