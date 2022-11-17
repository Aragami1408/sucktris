#include "sucktris.h"


sucktris *sucktris_init() {
	sucktris *st = malloc(sizeof(sucktris));
	if(!st) {
		log_err("Failed to initialize sucktris\n");
		return NULL;
	}

	if(ini_parse("res/settings.ini",settings_init,&st->user_config) < 0) {
		log_err("Failed to load 'res/settings.ini'\n");
		return NULL;
	}

	if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		log_err("SDL_Init failed (%s)\n",SDL_GetError());
		return NULL;
	} else log_info("SDL_Init done successfully\n");
	
	st->window = SDL_CreateWindow(
			"SuckTris", 
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, 
			st->user_config.video_width, 
			st->user_config.video_height, 
			SDL_WINDOW_SHOWN);
	if(!st->window) {
		log_err("SDL_Window failed to be created (%s)\n", SDL_GetError());
		return NULL;
	} else log_info("SDL_Window is created successfully\n");

	st->renderer = SDL_CreateRenderer(st->window, -1, SDL_RENDERER_ACCELERATED);
	if(!st->renderer) {
		log_err("SDL_Renderer failed to be created (%s)\n", SDL_GetError());
		return NULL;
	} else log_info("SDL_Renderer is created successfully\n");

	log_info("SuckTris is created successfully\n");

	st->running = true;

	return st;
}

void sucktris_handleEvents(sucktris *st) {
	if(SDL_PollEvent(&(st->event))) {
		switch(st->event.type) {
			case SDL_QUIT:
				log_info("SDL_Event: SDL_QUIT\n");
				st->running = false;
			break;

			default:
			break;
		}
	}
}

void sucktris_update(sucktris *st) {
	
}

void sucktris_render(sucktris *st) {
	SDL_SetRenderDrawColor(st->renderer,0,0,0,255);
	SDL_RenderClear(st->renderer);
	SDL_RenderPresent(st->renderer);
}

void sucktris_quit(sucktris *st) {
	log_info("Quitting SuckTris\n");
	SDL_DestroyRenderer(st->renderer);
	SDL_DestroyWindow(st->window);
	SDL_Quit();
}
