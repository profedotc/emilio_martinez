#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 4

void gol_init(int world[][SIZE][SIZE]);
void gol_print(int world[][SIZE][SIZE], int selected_world);
void gol_step(int world[][SIZE][SIZE], int selected_world);
int gol_count_neighbors(int world[][SIZE][SIZE], int i, int j, int selected_world);
bool gol_get_cell(int world[][SIZE][SIZE], int i, int j, int selected_world);

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

void gol_init(int world[][SIZE][SIZE])
{
	for (int k = 0; k < 2; k++)
	{

		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				world[k][i][j] = false;
			}
		}
		world[k][1][0] = true;
		world[k][1][1] = true;
		world[k][1][2] = true;
	}
}

void gol_print(int world[][SIZE][SIZE], int selected_world)
{

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			printf("%c", world[selected_world][i][j] ? '#' : '.');
		}
		printf("\n");
	}
}

void gol_step(int world[][SIZE][SIZE], int selected_world)
{
	int other_world = !selected_world;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			int alives_neighbors = gol_count_neighbors(world, i, j, selected_world);
			if (world[selected_world][i][j] && (alives_neighbors < 2 || alives_neighbors > 3))
			{
				world[other_world][i][j] = 0;
			}
			if (!world[selected_world][i][j] && alives_neighbors == 3)
			{
				world[other_world][i][j] = 1;
			}
		}
	}
}

bool gol_get_cell(int world[][SIZE][SIZE], int i, int j, int selected_world)
{
	int cell;
	if (i >= 0 && j >= 0 && i < SIZE && j < SIZE)
	{
		cell = world[selected_world][i][j];
	}
	else
	{
		cell = 0;
	}
	return cell;
}

int gol_count_neighbors(int world[][SIZE][SIZE], int i, int j, int selected_world)
{
	int count_neighbors = 0;
	for (int x = i - 1; x < i + 2; x++)
	{
		for (int y = j - 1; y < j + 2; y++)
		{
			if (gol_get_cell(world, x, y, selected_world))
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
