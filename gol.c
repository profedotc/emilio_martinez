#include <stdio.h>
#include <stdbool.h>
#include "gol.h"

static bool get_cell(struct gol *g, int i, int j);
static int count_neighbors(struct gol *g, int i, int j);

void gol_init(struct gol *g)
{
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      g->worlds[0][i][j] = false;
    }
  }
  g->worlds[0][1][0] = true;
  g->worlds[0][1][1] = true;
  g->worlds[0][1][2] = true;
  g->current_world = 0;
}

void gol_print(struct gol *g)
{

  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      printf("%c", g->worlds[g->current_world][i][j] ? '#' : '.');
    }
    printf("\n");
  }
}

void gol_step(struct gol *g)
{
  int other_world = !g->current_world;
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      int alives_neighbors = count_neighbors(g, i, j);
      g->worlds[other_world][i][j] =
          (g->worlds[g->current_world][i][j] && alives_neighbors == 2) || alives_neighbors == 3;
    }
  }
  g->current_world = !g->current_world;
}

static bool get_cell(struct gol *g, int i, int j)
{
  int cell;
  if (i >= 0 && j >= 0 && i < SIZE && j < SIZE)
  {
    cell = g->worlds[g->current_world][i][j];
  }
  else
  {
    cell = 0;
  }
  return cell;
}

static int count_neighbors(struct gol *g, int i, int j)
{
  int count_neighbors = 0;
  for (int x = i - 1; x < i + 2; x++)
  {
    for (int y = j - 1; y < j + 2; y++)
    {
      if (get_cell(g, x, y))
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