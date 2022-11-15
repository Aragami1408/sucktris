#ifndef SETTINGS_H
#define SETTINGS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct settings settings;

struct settings {
    int video_width;
    int video_height;
};

int handler(void *user, const char *section, const char *name, const char *value);

#endif