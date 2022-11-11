#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "sucktris.h"

int main(int argc, char *argv[]) {
	sucktris *st = NULL;

	while(sucktris_isRunning(st)) {
		sucktris_handleEvents(st);
		sucktris_update(st);
		sucktris_render(st);
	}	

}
