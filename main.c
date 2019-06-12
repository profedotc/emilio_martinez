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
	gol_alloc(&g, ROWS, COLS);
	gol_init(&g, ROWS, COLS);
	do
	{
		printf("\033cIteration %d\n", it);
		gol_print(&g, ROWS, COLS);

		gol_step(&g, ROWS, COLS);
		++it;
	} while (getchar() != 'q');

	gol_free(&g, ROWS);
	return EXIT_SUCCESS;
}