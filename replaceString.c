#include "main.h"

/**
 * replaceString - replaces string
 * @old: address of old string
 * @new: new string
 * Return: 1 if replaced, 0 otherwise
 */

int replaceString(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
