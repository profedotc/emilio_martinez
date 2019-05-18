#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 4

void gol_init(int world[][SIZE]);
void gol_print(int world[][SIZE]);
void gol_step(int world[][SIZE], int world2[][SIZE]);
int gol_count_neighbors(int world[][SIZE], int i, int j);
bool gol_get_cell(int world[][SIZE], int i, int j);
void gol_copy(int world[][SIZE], int world2[][SIZE]);

int main()
{
	int it = 0;
	int world[SIZE][SIZE], world2[SIZE][SIZE];
	gol_init(world);
	gol_init(world2);

	do
	{
		printf("\033cIteration %d\n", it);
		gol_print(world);

		gol_step(world, world2);
		gol_copy(world2, world);
		++it;
	} while (getchar() != 'q');

	return EXIT_SUCCESS;
}

void gol_init(int world[][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			world[i][j] = false;
		}
	}
	world[1][0] = true;
	world[1][1] = true;
	world[1][2] = true;
}

void gol_print(int world[][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			printf("%c", world[i][j] ? '#' : '.');
		}
		printf("\n");
	}
}

void gol_step(int world[][SIZE], int world2[][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			int alives_neighbors = gol_count_neighbors(world, i, j);
			if (world[i][j] && (alives_neighbors < 2 || alives_neighbors > 3))
			{
				world2[i][j] = 0;
			}
			if (!world[i][j] && alives_neighbors == 3)
			{
				world2[i][j] = 1;
			}
		}
	}
}

bool gol_get_cell(int world[][SIZE], int i, int j)
{
	int cell;
	if (i >= 0 && j >= 0 && i < SIZE && j < SIZE)
	{
		cell = world[i][j];
	}
	else
	{
		cell = 0;
	}
	return cell;
}

int gol_count_neighbors(int world[][SIZE], int i, int j)
{
	int count_neighbors = 0;
	for (int x = i - 1; x < i + 2; x++)
	{
		for (int y = j - 1; y < j + 2; y++)
		{
			if (gol_get_cell(world, x, y))
			{
				if (x == i && y != j || x != i && y == j || x != i && y != j)
				{
					count_neighbors++;
				}
			}
		}
	}
	return count_neighbors;
}

void gol_copy(int world[][SIZE], int world2[][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			world2[i][j] = world[i][j];
		}
	}
}
