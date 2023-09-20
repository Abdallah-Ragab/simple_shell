#include "main.h"

/**
 * _strcpy - copies a string
 * @dest: destination
 * @src: source
 * Return: pointer to destination
 */

char *_strcpy(char *dest, char *src)
{
	int x = 0;

	if (dest == src || src == 0)
	{
		return (dest);
	}
	while (src[x])
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = 0;
	return (dest);
}
