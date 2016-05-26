#include "Horse.h"
#include "Rider.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	Rider *riders = new Rider[30];
	Horse *horses = new Horse[30];

	for (int i = 0; i < 30; ++i)
	{
		printf("%s\n", horses[i].description().c_str());
		printf("%s\n", riders[i].description().c_str());
	}
}