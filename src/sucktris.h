#ifndef SUCKTRIS_H
#define SUCKTRIS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <stdio.h>
#include <stdbool.h>

typedef struct sucktris sucktris;

struct sucktris {
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event event;

	bool running;
};

sucktris *sucktris_init(const char *title, int width, int height, bool fullscreen);

void sucktris_handleEvents(sucktris *st);
void sucktris_update(sucktris *st);
void sucktris_render(sucktris *st);

void sucktris_quit(sucktris *st);



#endif
