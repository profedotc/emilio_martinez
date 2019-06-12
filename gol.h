#ifndef _GOL_H
#define _GOL_H_

struct gol
{
  bool **worlds[2];
};

void gol_init(struct gol *g, int rows, int cols);
void gol_print(const struct gol *g, int rows, int cols);
void gol_step(struct gol *g, int rows, int cols);
void gol_alloc(struct gol *g, int rows, int cols);
void gol_free(struct gol *g, int cols);

#endif
