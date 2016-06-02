#include "Horse.h"
#include "Rider.h"
#include "Race.h"
#include <iostream>
#include <stdlib.h>
#include <cstdio>

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	int cash = 200;
	char end = '\0';
	int amoutOfCompetitors = 0;

	cout << "Witamy w symulatorze wyscigow konnych!\n";

	while(end != 27 && cash)
	{
		cout << "Podaj liczbe zawodnikow (od 2 do 8): ";
		cin >> amoutOfCompetitors;

		while(amoutOfCompetitors < 1 || amoutOfCompetitors > 8)
		{
			cout << "Cos poszlo nie tak, podaj liczbe zawodnikow (od 2 do 8): ";
			cin.clear();
			cin.ignore(1000,'\n');
			cin >> amoutOfCompetitors;
		}

		Race race(amoutOfCompetitors);

		race.chanceToGo();
		race.descriptionOfCompetitors();

		int shot = 0;
		cout << "\nObstaw zawodnika, nascisnij klawisz (od 1 do " << amoutOfCompetitors << "): ";
		cin >> shot;

		while(shot < 1 || shot > amoutOfCompetitors)
		{
			cout << "Cos poszlo nie tak, obstaw zawodnika, nascisnij klawisz (od 1 do " << amoutOfCompetitors << "): ";
			cin.clear();
			cin.ignore(1000,'\n');
			cin >> shot;
		}

		int bet = 0;
		cout << "\nMasz " << cash << " zlotych. Ile chcesz obstawic? [zl]: ";
		cin >> bet;

		while(bet < 1 || bet > cash)
		{
			cout << "Cos poszlo nie tak, ile chcesz obstawic? [zl]: ";
			cin.clear();
			cin.ignore(1000,'\n');
			cin >> bet;
		}
		
		cash -= bet;
		if(cash < 0)
			cash = 0;

		race.startRace();

		cout << "\nNacisnij enter by kontynuowac\n\n";
		getchar();
		getchar();
		system("clear");

		race.descriptionOfWinner();

		if(race.getHighScore() == shot)
		{
			cout << "\n\nBrawo! Dobrze obstawiłeś! Wygrywasz " << bet * amoutOfCompetitors << " zlotych\n";
			cash += bet* amoutOfCompetitors;
		}
		else		
			cout << "\n\nObstawiales inaczej, wiec niestety tym razem sie nie udalo :(\n";

		usleep(1000000);

		cout << "Stan Twojego konta wynosi " << cash << " zl. \n\n";

		race.clear();

		cout << "Wcisnij enter by kontunuowac lub escape by zakonczyc\n";
		end = getchar();
	}

}
