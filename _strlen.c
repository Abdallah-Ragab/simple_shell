#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length of string
 */

int _strlen(char *s)
{
	int x = 0;

	if (!s)
	{
		return (0);
	}

	while (*s++)
	{
		x++;
	}
	return (x);
}
