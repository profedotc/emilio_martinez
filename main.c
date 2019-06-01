#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gol.h"

int main()
{
	int it = 0;
	struct gol g;
	gol_init(&g);
	do
	{
		printf("\033cIteration %d\n", it);
		gol_print(&g);

		gol_step(&g);
		++it;
	} while (getchar() != 'q');

	return EXIT_SUCCESS;
}