#ifndef _GOL_H
#define _GOL_H_

#define ROWS 10
#define COLS 10

struct gol
{
  bool **worlds[2];
};

void gol_init(struct gol *g, const int rows, const int cols);
void gol_print(const struct gol *g, const int rows, const int cols);
void gol_step(struct gol *g, const int rows, const int cols);
void gol_alloc(struct gol *g, const int rows, const int cols);
void gol_free(struct gol *g, const int cols);

#endif
