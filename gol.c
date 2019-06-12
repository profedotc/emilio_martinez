#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gol.h"

enum world_state
{
  CURRENT = 0,
  NEXT = 1,
};

static bool get_cell(const struct gol *g, int i, int j, int rows, int cols);
static int count_neighbors(const struct gol *g, int i, int j, int rows, int cols);

void gol_alloc(struct gol *g, int rows, int cols)
{
  g->worlds[CURRENT] = (bool **)malloc(rows * sizeof(bool *));
  g->worlds[NEXT] = (bool **)malloc(rows * sizeof(bool *));
  for (int i = 0; i < rows; i++)
  {
    g->worlds[CURRENT][i] = (bool *)malloc(cols * sizeof(bool));
    g->worlds[NEXT][i] = (bool *)malloc(cols * sizeof(bool));
  }
}
void gol_free(struct gol *g, int cols)
{
  for (int i = 0; i < cols; i++)
  {
    free(g->worlds[NEXT][i]);
    free(g->worlds[CURRENT][i]);
  }
  free(g->worlds[NEXT]);
  free(g->worlds[CURRENT]);
}

void gol_init(struct gol *g, int rows, int cols)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      g->worlds[0][i][j] = false;
    }
  }
  g->worlds[CURRENT][1][0] = true;
  g->worlds[CURRENT][1][1] = true;
  g->worlds[CURRENT][1][2] = true;
}

void gol_print(const struct gol *g, int rows, int cols)
{

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      printf("%c", g->worlds[CURRENT][i][j] ? '#' : '.');
    }
    printf("\n");
  }
}

void gol_step(struct gol *g, int rows, int cols)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      int alives_neighbors = count_neighbors(g, i, j, rows, cols);
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

static bool get_cell(const struct gol *g, int i, int j, int rows, int cols)
{
  int cell = 0;
  if (i >= 0 && j >= 0 && i < rows && j < cols)
  {
    cell = g->worlds[CURRENT][i][j];
  }
  return cell;
}

static int count_neighbors(const struct gol *g, int i, int j, int rows, int cols)
{
  int count_neighbors = -get_cell(g, i, j, rows, cols);
  for (int x = i - 1; x < i + 2; x++)
  {

    for (int y = j - 1; y < j + 2; y++)
    {
      if (get_cell(g, x, y, rows, cols))
        count_neighbors++;
    }
  }
  return count_neighbors;
}
