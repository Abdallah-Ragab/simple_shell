#include "main.h"

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous mallocated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 * Return: pointer to da oldblock named
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *x;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	x = malloc(new_size);
	if (!x)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		x[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (x);
}
