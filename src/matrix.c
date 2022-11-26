#include "matrix.h"

cell cell_init() {
	cell c;
	c.exists = false;
	c.color.r = 255;
	c.color.g = 255;
	c.color.b = 255;
	c.color.a = 255;
	return c;
}

void cell_setcolor(cell *c, SDL_Color color) {
	c->color = color;
	c->exists = true;
}

void cell_remove(cell *c) {
	c->exists = false;
}

matrix *matrix_init(int x, int y, int width, int height, int cell_size) {
	
	matrix *m = (matrix *) malloc(sizeof(matrix));
	if(!m) {
		log_err("Failed to malloc %zu to matrix *\n", sizeof(matrix));
		return NULL;
	}	
	m->x = x;
	m->y = y;
	m->width = width;
	m->height = height;
	m->cell_size = cell_size;

	m->cells = (cell *) malloc(sizeof(cell) * (width * height));
	if(!m->cells) {
		log_err("Failed to malloc %zu to cell *\n", sizeof(cell) * (width * height));
		return NULL;
	}	

	return m;
}

void matrix_setcell(matrix *m, int x, int y, SDL_Color c) {
}
