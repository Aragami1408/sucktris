#include "vec2f.h"

vec2f *vec2f_init(float x, float y) {
	vec2f *v = malloc(sizeof(vec2f));

	v->x = x;
	v->y = y;

	return v;
}

void vec2f_add(vec2f *src, vec2f *dest) {
	src->x += dest->x;
	src->y += dest->y;
}
void vec2f_mult(vec2f *src, float dest) {
	src->x *= dest;
	src->y *= dest;
}
