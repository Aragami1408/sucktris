#ifndef SETTINGS_H
#define SETTINGS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct settings settings;


struct settings {
	// [controls]
	 int control_left;
	 int control_right; 
	 int control_soft_drop;
	 int control_hard_drop;
	 int control_rot_ccw;
	 int control_rot_cw;
	 int control_rot_180;
	 int control_hold;
	 int control_quit;
	 int control_retry;

	// [video]
     int video_width;
     int video_height;
	 int video_matrix_row;
	 int video_matrix_col;
	 int video_fps;
	
};

int settings_init(void *user, const char *section, const char *name, const char *value);

#endif
