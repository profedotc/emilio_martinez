#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gol.h"

int main()
{
	int it = 0;
	int selected_world = 0;
	int world[2][SIZE][SIZE];
	gol_init(world);

	do
	{
		printf("\033cIteration %d\n", it);
		gol_print(world, selected_world);

		gol_step(world, selected_world);
		++it;
		selected_world = !selected_world;
	} while (getchar() != 'q');

	return EXIT_SUCCESS;
}