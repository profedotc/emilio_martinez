#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gol.h"

#define ROWS 5
#define COLS 10

int main()
{
  struct gol g;

  gol_alloc(&g, ROWS, COLS);
  gol_init(&g, ROWS, COLS);

  for (int i = 0; i < 10; i++)
  {
    gol_step(&g, ROWS, COLS);
  }

  gol_free(&g, ROWS);
  return EXIT_SUCCESS;
}