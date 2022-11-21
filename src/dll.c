#include "dll.h"

static dll_node *dll_search_node(dll *list, int pos);
static dll_node *dll_init_node(void *data);

dll *dll_init() {
	dll *list = malloc(sizeof(dll));
	if(!list) {
		log_err("dll_list is failed to initialized\n");
		return NULL;
	}
	list->size = 0;
	list->first = NULL;
	list->last = NULL;

	return list;
}

void *dll_get(dll *list, int pos) {
	dll_node *node = dll_search_node(list, pos);
	if(!node) {
		log_err("dll_node not found in position: %d\n", pos);
		return NULL;
	}
	else return node->data;
}

void *dll_first(dll *list) {
	if(!list->first) {
		log_err("First node of the list is undefined\n");
		return NULL;
	}

	return list->first->data;
}

void *dll_last(dll *list) {
	if(!list->last) {
		log_err("Last node of the list is undefined\n");
		return NULL;
	}

	return list->last->data;

}

bool dll_add(dll *list, void *data, int pos) {
	if(pos > list->size) {
		log_err("Node position can't be greather than the list size\n");
		return false;
	}

	dll_node *new_node;
	dll_node *current_node;

	if(list->size == 0) {
		list->first = new_node;
		list->last = new_node;
		list->size++;
		return true;
	}

	current_node = dll_search_node(list, pos);
	if(current_node != NULL) {
		new_node->prev = current_node->prev;
		new_node->next = current_node;

		if(current_node->prev == NULL)
			list->first = new_node;
		else
			current_node->prev = new_node;

		current_node->prev = new_node;
	} 
	else {
		list->last->next = new_node;
		new_node->prev = list->last;
		list->last = new_node;
	}
	list->size++;
	return true;
}

void *dll_set(dll *list, void *data, int pos) {
	dll_node *current_node = dll_search_node(list, pos);
	if(!current_node) {
		log_err("dll_node not found in position: %d\n", pos);
		return NULL;
	}

	void *old_data = current_node->data;
	current_node->data = data;

	return old_data;
}

bool dll_pushfront(dll *list, void *data) {
	dll_node *new_node = dll_init_node(data);

	if(list->size == 0) list->last = new_node;
	else {
		list->first->prev = new_node;
		new_node->next = list->first;
	}
	list->first = new_node;
	list->size++;

	return true;
}

bool dll_pushback(dll *list, void *data) {
	dll_node *new_node = dll_init_node(data);

	if(list->size == 0) list->first = new_node;
	else {
		list->last->next = new_node;
		new_node->prev = list->last;
	}
	list->last = new_node;
	list->size++;

	return true;
}

void *dll_remove(dll *list, int pos) {
	dll_node *current_node = dll_search_node(list,pos);
	if(!current_node) {
		log_err("dll_node not found in position: %d\n", pos);
		return NULL;
	}
	void *data =current_node->data;

	if(!current_node->prev) 
		list->first = current_node->next;
	else 
		current_node->prev->next = current_node->next;

	if(!current_node->next) 
		list->last = current_node->prev;
	else 
		current_node->next->prev = current_node->prev;
}

void *dll_pop(dll *list) {
	if(!list) {
		log_err("List does not exist\n");
		return NULL;
	}

	dll_node *node = list->first;
	if(!node) {
		log_err("List node does not exist\n");
		return NULL;
	}

	void *data = node->data;

	if(dll_remove(list, 0) == NULL) {
		log_err("Can't remove first element from the list\n");
		return NULL;
	}

	return data;
}

void *dll_popBack(dll *list) {
	dll_node *node = list->last;

	if(!node) {
		log_err("List node does not exists\n");
		return NULL;
	}

	void *data = node->data;

	if(dll_remove(list, (list->size - 1)) == NULL) {
		log_err("Can't remove last element from the list\n");
		return NULL;
	}

	return data;
}

void dll_each(dll *list, void (*f)(void *)) {
	dll_node *current_node = list->first;
	while(current_node != NULL) {
		(*f)(current_node->data);
		current_node = current_node->next;
	}
}
void dll_eachReverse(dll *list, void (*f)(void *)) {
	dll_node *current_node = list->last;
	while(current_node != NULL) {
		(*f)(current_node->data);
		current_node = current_node->prev;
	}

}

void dll_clear(dll *list) {
	dll_node *current_node = list->first;
	dll_node *next_node;

	while(current_node != NULL) {
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}

	list->first = NULL;
	list->last = NULL;
	list->size = 0;
}

void dll_destroy(dll *list) {
	dll_node *current_node = list->first;
	dll_node *next_node;

	while(current_node != NULL) {
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}

	free(list);
}

static dll_node *dll_search_node(dll *list, int pos) {
	if(pos > list->size) {
		log_err("Node position can't be greater than the list size\n");
		return NULL;
	}

	dll_node *current_node;
	int current_pos;
	bool reverse;

	if(pos > ((list->size-1)/2)) {
		reverse = true;
		current_pos = list->size - 1;
		current_node = list->last;
	}
	else {
		reverse = false;
		current_pos = 0;
		current_node = list->first;
	}

	while(!current_node) {
		if(current_pos == pos) {
			break;
		}

		current_node = (reverse ? (current_node->prev) : (current_node->next));
		current_pos = (reverse ? (current_pos - 1) : (current_pos + 1));	
	}

	return current_node;
}



static dll_node *dll_init_node(void *data) {
	dll_node *node = malloc(sizeof(dll_node));
	if(!node) {
		log_err("dll_node is failed to initialized\n");
		return NULL;
	}

	node->data = data;
	node->prev = NULL;
	node->next = NULL;

	return node;
}





