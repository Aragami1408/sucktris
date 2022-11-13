#ifndef SUCKTRIS_H
#define SUCKTRIS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "board.h"

#include <stdio.h>
#include <stdbool.h>

typedef struct sucktris sucktris;

struct sucktris {
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event event;

	board *board;

	bool running;
};

/**
 * Initialize SuckTris's core structure consists of SDL_Window, SDL_Renderer and SDL_Event instance.
 *
 * @param title The title of the game window
 * @param width The width of the game window
 * @param height The height of the game window
 * @param fullscreen The game window's resolution will be set as full-screen if true
 *
 * @return a dynamically allocated sucktris instance if success, otherwise returns NULL
 *
 */
sucktris *sucktris_init(const char *title, int width, int height, bool fullscreen);

/**
 * Handle user events from peripherals.
 *
 * @param st sucktris pointer
 */
void sucktris_handleEvents(sucktris *st);

/**
 * Update entities before rendering.
 *
 * @param st sucktris pointer
 */
void sucktris_update(sucktris *st);

/**
 * Render updated entities to the game window.
 *
 * @param st sucktris pointer
 */
void sucktris_render(sucktris *st);

/**
 * Quit the game.
 *
 * @param st sucktris pointer
 */
void sucktris_quit(sucktris *st);



#endif
