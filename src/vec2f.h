#ifndef VEC2F_HH
#define VEC2F_HH

#include <stdlib.h>

typedef struct vec2f vec2f;

struct vec2f {
	float x;
	float y;
};

vec2f *vec2f_init(float x, float y);

void vec2f_add(vec2f *src, vec2f *dest);
void vec2f_mult(vec2f *src, float dest);


#endif
