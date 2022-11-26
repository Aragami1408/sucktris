#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h>
#include <SDL2/SDL.h>

#include "vec2f.h"
#include "dbg.h"

typedef struct cell cell;
typedef struct matrix matrix;

struct cell {
	bool exists;
	SDL_Color color;
};

cell cell_init();
void cell_setcolor(cell *c, SDL_Color color);
void cell_remove(cell *c);

struct matrix {
	cell *cells;
	int width;
	int height;
	int cell_size;
	int x;
	int y;
};

matrix *matrix_init(int x, int y, int width, int height, int cell_size);
void matrix_setcell(matrix *m, int x, int y, SDL_Color c);


#endif
