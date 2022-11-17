#include "vector.h"

vector *vector_init(size_t elements, size_t elemsize) {}

bool vector_free(vector *vector) {}

bool vector_isvalid(const vector *vector) {}

bool vector_insert(vector *vector, void *element, size_t size) {}

bool vector_remove(vector *vector, size_t index) {}

bool vector_pop_front(vector *vector) {}

bool vector_pop_back(vector *vector) {}

bool vector_resize(vector *vector) {}

void *vector_get(const vector *vector, size_t index) {}

bool vector_copy(const vector *vector, void *dest, size_t index) {}
