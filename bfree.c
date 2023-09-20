#include "main.h"

/**
 * bfree - frees a pointer anduts it address as NULL
 * @ptr: address
 * Return: 1 if freed succesfully, otherwise 0.
 */

int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
