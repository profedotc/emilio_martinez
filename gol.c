#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gol.h"

enum world_state
{
  CURRENT = 0,
  NEXT = 1,
};

static bool get_cell(const struct gol *g, int i, int j, int world);
static void set_cell(struct gol *g, int i, int j, int world, bool b);
static int count_neighbors(const struct gol *g, int i, int j);

bool gol_alloc(struct gol *g)
{
  g->worlds[CURRENT] = (bool *)malloc(g->size_x * g->size_y * sizeof(bool *));

  if (!g->worlds[CURRENT])
    return false;

  g->worlds[NEXT] = (bool *)malloc(g->size_x * g->size_y * sizeof(bool *));

  if (!g->worlds[NEXT])
    return false;

  return true;
}
void gol_free(struct gol *g)
{
  free(g->worlds[NEXT]);
  free(g->worlds[CURRENT]);
}

void gol_init(struct gol *g)
{
  for (int i = 0; i < g->size_x; i++)
  {
    for (int j = 0; j < g->size_y; j++)
    {
      set_cell(g, i, j, CURRENT, false);
    }
  }
  set_cell(g, 1, 0, CURRENT, true);
  set_cell(g, 1, 1, CURRENT, true);
  set_cell(g, 1, 2, CURRENT, true);
}

void gol_print(const struct gol *g)
{

  for (int i = 0; i < g->size_x; i++)
  {
    for (int j = 0; j < g->size_y; j++)
    {
      printf("%c", get_cell(g, i, j, CURRENT) ? '#' : '.');
    }
    printf("\n");
  }
}

void gol_step(struct gol *g)
{
  for (int i = 0; i < g->size_x; i++)
  {
    for (int j = 0; j < g->size_y; j++)
    {
      int alives_neighbors = count_neighbors(g, i, j);
      if (get_cell(g, i, j, CURRENT) && (alives_neighbors < 2 || alives_neighbors > 3))
      {
        set_cell(g, i, j, NEXT, 0);
      }
      else if (get_cell(g, i, j, CURRENT) && (alives_neighbors == 2 || alives_neighbors == 3))
      {
        set_cell(g, i, j, NEXT, 1);
      }
      else if (!(get_cell(g, i, j, CURRENT)) && alives_neighbors == 3)
      {
        set_cell(g, i, j, NEXT, 1);
      }
      else if (!(get_cell(g, i, j, CURRENT)) && alives_neighbors != 3)
      {
        set_cell(g, i, j, NEXT, 0);
      }
    }
  }
  bool *aux_array = g->worlds[CURRENT];
  g->worlds[CURRENT] = g->worlds[NEXT];
  g->worlds[NEXT] = aux_array;
}

static bool get_cell(const struct gol *g, int i, int j, int world)
{
  int cell = 0;
  if (i >= 0 && j >= 0 && i < g->size_x && j < g->size_y)
  {
    cell = g->worlds[world][i * g->size_y + j];
  }
  return cell;
}

static int count_neighbors(const struct gol *g, int i, int j)
{
  int count_neighbors = -get_cell(g, i, j, CURRENT);
  for (int x = i - 1; x < i + 2; x++)
  {

    for (int y = j - 1; y < j + 2; y++)
    {
      if (get_cell(g, x, y, CURRENT))
        count_neighbors++;
    }
  }
  return count_neighbors;
}

static void set_cell(struct gol *g, int i, int j, int world, bool b)
{
  if (i >= 0 && j >= 0 && i < g->size_x && j < g->size_y)
  {
    g->worlds[world][i * g->size_y + j] = b;
  }
}