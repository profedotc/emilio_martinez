#ifndef _GOL_H
#define _GOL_H_

#define SIZE 4

struct gol
{
  bool **worlds[2];
};

enum world_state
{
  CURRENT = 0,
  NEXT = 1,
};

void gol_init(struct gol *g);
void gol_print(struct gol *g);
void gol_step(struct gol *g);
bool **gol_alloc(void);
void gol_free(struct gol *g);

#endif
