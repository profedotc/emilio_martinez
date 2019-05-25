#ifndef _GOL_H
#define _GOL_H_

#define SIZE 4

void gol_init(int world[][SIZE][SIZE]);
void gol_print(int world[][SIZE][SIZE], int selected_world);
void gol_step(int world[][SIZE][SIZE], int selected_world);
int gol_count_neighbors(int world[][SIZE][SIZE], int i, int j, int selected_world);
bool gol_get_cell(int world[][SIZE][SIZE], int i, int j, int selected_world);

#endif