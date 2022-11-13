#include "sucktris.h"
#include "dbg.h"


sucktris *sucktris_init(const char *title, int width, int height, bool fullscreen) {
	sucktris *st = malloc(sizeof(sucktris));
	if(!st) {
		log_err("Failed to initialize sucktris\n");
		return NULL;
	}

	if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		log_err("SDL_Init failed\n");
		return NULL;
	} else log_info("SDL_Init done successfully\n");
	
	st->window = SDL_CreateWindow(
			title, 
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, 
			width, 
			height, 
			(fullscreen)?SDL_WINDOW_FULLSCREEN:SDL_WINDOW_SHOWN);
	if(!st->window) {
		log_err("SDL_Window failed to be created\n");
		return NULL;
	} else log_info("SDL_Window is created successfully\n");

	st->renderer = SDL_CreateRenderer(st->window, -1, SDL_RENDERER_ACCELERATED);
	if(!st->renderer) {
		log_err("SDL_Renderer failed to be created\n");
		return NULL;
	} else log_info("SDL_Renderer is created successfully\n");

	log_info("SuckTris is created successfully\n");

	st->board = board_init(st->renderer,"res/img/skin.png");		
	if(!st->board) {
		log_err("Game board failed to be created\n");
		return NULL;
	} else log_info("Game board is created successfully\n");

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
	board_draw(st->board);
	SDL_RenderPresent(st->renderer);
}

void sucktris_quit(sucktris *st) {
	log_info("Quitting Sucktris\n");
	SDL_DestroyRenderer(st->renderer);
	SDL_DestroyWindow(st->window);
	SDL_Quit();
}
