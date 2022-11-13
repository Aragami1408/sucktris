#ifndef BOARD_H
#define BOARD_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "dbg.h"


typedef struct board board;

struct board {
	SDL_Texture *tex;
	SDL_Renderer *renderer;
};

board *board_init(SDL_Renderer *renderer, const char *filename);

void board_draw(board *b);

#endif
