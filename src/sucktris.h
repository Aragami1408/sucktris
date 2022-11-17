#ifndef SUCKTRIS_H
#define SUCKTRIS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>


#include <stdio.h>
#include <stdbool.h>

#include "settings.h"
#include "dbg.h"
#include "ini.h"


typedef struct sucktris sucktris;

struct sucktris {
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event event;

	settings user_config;


	bool running;
};

/**
 * Initialize SuckTris's core structure consists of SDL instances and entities
 *
 * @return a dynamically allocated sucktris instance if success, otherwise returns NULL
 *
 */
sucktris *sucktris_init();

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
