#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gol.h"

static bool get_cell(struct gol *g, int i, int j);
static int count_neighbors(struct gol *g, int i, int j);

bool **gol_alloc(void)
{
  bool **array = (bool **)malloc(SIZE * sizeof(bool *));
  for (int i = 0; i < SIZE; i++)
    array[i] = (bool *)malloc(SIZE * sizeof(bool));
  return array;
}

void gol_free(struct gol *g)
{
  for (int i = 0; i < SIZE; i++)
  {
    free(g->worlds[NEXT][i]);
    free(g->worlds[CURRENT][i]);
  }
  free(g->worlds[NEXT]);
  free(g->worlds[CURRENT]);
}

void gol_init(struct gol *g)
{
  g->worlds[CURRENT] = gol_alloc();
  g->worlds[NEXT] = gol_alloc();
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      g->worlds[0][i][j] = false;
    }
  }
  g->worlds[CURRENT][1][0] = true;
  g->worlds[CURRENT][1][1] = true;
  g->worlds[CURRENT][1][2] = true;
}

void gol_print(struct gol *g)
{

  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      printf("%c", g->worlds[CURRENT][i][j] ? '#' : '.');
    }
    printf("\n");
  }
}

void gol_step(struct gol *g)
{
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      int alives_neighbors = count_neighbors(g, i, j);
      if (g->worlds[CURRENT][i][j] && (alives_neighbors < 2 || alives_neighbors > 3))
      {
        g->worlds[NEXT][i][j] = 0;
      }
      else if (g->worlds[CURRENT][i][j] && (alives_neighbors == 2 || alives_neighbors == 3))
      {
        g->worlds[NEXT][i][j] = 1;
      }
      else if (!(g->worlds[CURRENT][i][j]) && alives_neighbors == 3)
      {
        g->worlds[NEXT][i][j] = 1;
      }
      else if (!(g->worlds[CURRENT][i][j]) && alives_neighbors != 3)
      {
        g->worlds[NEXT][i][j] = 0;
      }
    }
  }
  bool **aux_array = g->worlds[CURRENT];
  g->worlds[CURRENT] = g->worlds[NEXT];
  g->worlds[NEXT] = aux_array;
}