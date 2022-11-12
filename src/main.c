#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "sucktris.h"

int main() {
	sucktris *st = sucktris_init("Sucktris", 1280, 720);
	if(!st) {
		return -1;
	}

	while(st->running) {
		sucktris_handleEvents(st);
		sucktris_update(st);
		sucktris_render(st);
	}

	sucktris_quit(st);

	return 0;
}
