#include "main.h"

/**
 * ffree - frees a string of strings
 * @pp: string of strings
 * Retrun: void
 */

void ffree(char **pp)
{
	char **s = pp;

	if (!pp)
	{
		return;
	}
	while (*pp)
	{
		free(*pp++);
	}
	free(s);
}
