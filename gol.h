#ifndef _GOL_H
#define _GOL_H_

struct gol
{
  bool **worlds[2];
  int size_x;
  int size_y;
};

void gol_init(struct gol *g);
void gol_print(const struct gol *g);
void gol_step(struct gol *g);
bool gol_alloc(struct gol *g);
void gol_free(struct gol *g);

#endif
