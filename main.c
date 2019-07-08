#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gol.h"

#define ROWS 5
#define COLS 10

int main()
{
	int it = 0;
	struct gol g;
	g.size_x = ROWS;
	g.size_y = COLS;
	gol_alloc(&g);
	gol_init(&g);
	do
	{
		printf("\033cIteration %d\n", it);
		gol_print(&g);

		gol_step(&g);
		++it;
	} while (getchar() != 'q');

	gol_free(&g);
	return EXIT_SUCCESS;
}