#include "settings.h"

int handler(void *user, const char *section, const char *name, const char *value) {
    settings *s = (settings *)user;

    #define MATCH(s, n) strcmp(section, s) == 0 & strcmp(name, n) == 0
    if(MATCH("video", "width")) {
        s->video_width = atoi(value);
    }
    if(MATCH("video", "height")) {
        s->video_height = atoi(value);
    }
    else return 0;
    
    return 1;
}

