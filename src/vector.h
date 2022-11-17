#ifndef VECTOR_H
#define VECTOR_H

#include "dbg.h"

#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
	unsigned char *buffer;
		size_t capacity;
		size_t currsize;
		size_t elements;
		size_t elemsize;
} vector;

/**
 * vector_init
 *
 * Initializes a new vector.
 *
 * Parameters:
 *    elements: The number of elements to allocate storage for.
 *    elemsize: The size of each element.
 * Returns:
 *    vector instance if succeed, otherwise NULL
 */

vector *vector_init(size_t elements, size_t elemsize);

/**
 * vector_free
 *
 * Frees a vector instance.
 *
 * Parameters:
 *    vector: A reference to a vector.
 * Returns:
 *    true if the vector was freed.
 *    false if the vector was not freed.
 */

bool vector_free(vector *vector);

/**
 * vector_isvalid
 *
 * Determines whether or not a vector is valid.
 *
 * Parameters:
 *    vector: A reference to a vector.
 * Returns:
 *    true if the vector is valid.
 *    false if the vector is not valid.
 */

bool vector_isvalid(const vector *vector);

/**
 * vector_insert
 *
 * Inserts an element at the back of the vector.
 *
 * Parameters:
 *    vector: A reference to a vector.
 *    element: A reference to the element.
 *    size: The size of the element.
 * Returns:
 *    true if the element was added to the vector.
 *    false if the element was not added to the vector.
 */

bool vector_insert(vector *vector, void *element, size_t size);

/**
 * vector_remove
 *
 * Removes an element from the vector.
 *
 * Parameters:
 *    vector: A reference to a vector.
 *    index: The index of the element to remove.
 * Returns:
 *    true if the element was removed from the vector.
 *    false if the element was not removed from the vector.
 */

bool vector_remove(vector *vector, size_t index);

/**
 * vector_pop_front
 *
 * Removes the first element from the vector.
 *
 * Parameters:
 *    vector: A reference to a vector.
 * Returns:
 *    true if the first element was removed from the vector.
 *    false if the first element was not removed from the vector.
 */

bool vector_pop_front(vector *vector);

/**
 * vector_pop_back
 *
 * Removes the last element from the vector.
 *
 * Parameters:
 *    vector: A reference to a vector.
 * Returns:
 *    true if the last element was removed from the vector.
 *    false if the last element was not removed from the vector.
 */

bool vector_pop_back(vector *vector);

/**
 * vector_resize
 *
 * Resizes the vector to be 2x the current capacity.
 *
 * Parameters:
 *    vector: A reference to a vector.
 * Returns:
 *    true if the vector was resized.
 *    false if the vector was not resized.
 */

bool vector_resize(vector *vector);

/**
 * vector_get
 *
 * Get a value from the vector.
 *
 * Parameters:
 *    vector: A reference to a vector.
 *    index: The index of the element to get.
 * Returns:
 *    The element on success.
 *    NULL on failure.
 */

void *vector_get(const vector *vector, size_t index);

/**
 * vector_copy
 *
 * Copy a value from the vector to a destination.
 *
 * Parameters:
 *    vector: A reference to a vector.
 *    dest: The destination for the data.
 *    index: The index of the element to copy.
 * Returns:
 *    true if the element was copied.
 *    false if the element was not copied.
 */

bool vector_copy(const vector *vector, void *dest, size_t index);


#endif
