#ifndef _GOL_H
#define _GOL_H_

#define SIZE 4

struct gol
{
  bool worlds[2][SIZE][SIZE];
  bool current_world;
};

void gol_init(struct gol *g);
void gol_print(struct gol *g);
void gol_step(struct gol *g);
int gol_count_neighbors(struct gol *g, int i, int j);
bool gol_get_cell(struct gol *g, int i, int j);

#endif
