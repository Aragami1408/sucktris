#include <stdbool.h>


#include "dbg.h"
#include "sucktris.h"
#include "settings.h"
#include "ini.h"

int main(int argc, char **argv) {

	settings user_config;	

	if(ini_parse("res/settings.ini", settings_init, &user_config) < 0) {
		log_err("Failed to load res/settings.ini\n");
		return 1;
	}

	sucktris *st = sucktris_init();
	if(!st) {
		return 1;
	}
	
	const int FPS = 60;
	const int frame_delay = 1000 / FPS;
	
	Uint32 frame_start;
	int frame_time;

	while(st->running) {
		frame_start = SDL_GetTicks();
		sucktris_handleEvents(st);
		sucktris_update(st);
		sucktris_render(st);
		frame_time = SDL_GetTicks() - frame_start;
		if(frame_delay > frame_time) {
			SDL_Delay(frame_delay - frame_time);
		}
	}

	sucktris_quit(st);

	return 0;
}
