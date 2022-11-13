#include <stdbool.h>


#include "sucktris.h"

int main() {
	sucktris *st = sucktris_init("SuckTris", 1280,720, false);
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
