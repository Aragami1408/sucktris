#include "settings.h"

int settings_init(void *user, const char *section, const char *name, const char *value) {
	settings *s = (settings *)user;

#define MATCH(s, n) strcmp(section, s) == 0 & strcmp(name, n) == 0
	if(MATCH("video", "width")) {
		s->video_width = atoi(value);
	} else if(MATCH("video", "height")) {
		s->video_height = atoi(value);
	} else if(MATCH("video", "matrix_row")) {
		s->video_matrix_row = atoi(value);
	} else if(MATCH("video", "matrix_col")) {
		s->video_matrix_col = atoi(value);
	} else if(MATCH("video", "fps")) {
		s->video_fps = atoi(value);
	} else return 0;

	return 1;
}

