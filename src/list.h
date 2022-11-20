#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct list_node list_node;
typedef struct list list;

struct list_node {
	list_node *prev;
	list_node *next;
	void *value;
};

struct list {
	list_node *first;
	list_node *last;
	size_t len;
};

void list_node_init(list_node *n, int v);
list_node *list_begin(list *l);
list_node *list_end(list *l);
list_node *list_advance(list_node *i);

void list_init(list *l);
void list_insert(list *l, list_node *where, void *value);
void list_pushfront(list *l, void *value);
void list_pushback(list *l, void *value);
void list_erase(list *l, list_node *where);
void list_clear(list *l);
void list_done(list *l);

#endif
