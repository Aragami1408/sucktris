#ifndef DLL_H
#define DLL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "dbg.h"

typedef struct dll_node dll_node;
typedef struct dll dll;

struct dll_node {
	void *data;
	dll_node *prev;
	dll_node *next;
};

struct dll {
	int size;
	dll_node *first;
	dll_node *last;
};

dll *dll_init();

void *dll_get(dll *list, int pos);
void *dll_first(dll *list);
void *dll_last(dll *list);

bool dll_add(dll *list, void *data, int pos);
void *dll_set(dll *list, void *data, int pos);
bool dll_pushfront(dll *list, void *data);
bool dll_pushback(dll *list, void *data);

void *dll_remove(dll *list, int pos);
void *dll_pop(dll *list);
void *dll_popBack(dll *list);

void dll_each(dll *list, void (*f)(void *));
void dll_eachReverse(dll *list, void (*f)(void *));

void dll_clear(dll *list);
void dll_destroy(dll *list);

#endif
