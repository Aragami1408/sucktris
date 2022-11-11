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

inline bool sucktris_isRunning(sucktris *st) {return st->running;}

sucktris *sucktris_init(int width, int height);
void sucktris_handleEvents(sucktris *st);
void sucktris_update(sucktris *st);
void sucktris_render(sucktris *st);
void sucktris_quit(sucktris *st);



#endif
