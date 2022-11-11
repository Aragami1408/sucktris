#include "sucktris.h"


sucktris *sucktris_init(int width, int height) {
	sucktris *st = malloc(sizeof(sucktris));
	if(!st) {
		printf("Failed to initialize game logic\n");
		return NULL;
	}

	if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("Failed to initialize SDL subsystems: %s\n", SDL_GetError());
		return NULL;
	}
	else {
		st->window = SDL_CreateWindow(
				"SuckTris", 
				SDL_WINDOWPOS_CENTERED, 
				SDL_WINDOWPOS_CENTERED,
				width,
				height,
				0);
		if(!st->window) {
			printf("Failed to initialize SDL Window: %s\n", SDL_GetError());
			return NULL;
		}
		
		st->renderer = SDL_CreateRenderer(st->window, -1, 0);
		if(!st->renderer) {
			printf("Failed to initialize SDL Renderer: %s\n", SDL_GetError());
			return NULL;	
		}	
		st->running = true;
	}


	return st;
}

void sucktris_handleEvents(sucktris *st) {
	while(SDL_PollEvent(&st->event)) {
		switch(st->event.type) {
			case SDL_QUIT:
				st->running = false;
			break;
			
		}
	}
}

void sucktris_update(sucktris *st) {}

void sucktris_render(sucktris *st) {
	SDL_SetRenderDrawColor(st->renderer,0,0,0,255);
	SDL_RenderClear(st->renderer);
	SDL_RenderPresent(st->renderer);
}

void sucktris_quit(sucktris *st) {
	SDL_DestroyRenderer(st->renderer);
	SDL_DestroyWindow(st->window);
	SDL_Quit();
}
