#include "main.h"

/**
 **_strncpy - copies a string
 *@dest: destination
 *@src: source
 *@n: amount of characters
 *Return: concatenated string
 */

char *_strncpy(char *dest, char *src, int n)
{
	int x, y;
	char *h = dest;

	x = 0;
	while (src[x] != '\0' && x < n - 1)
	{
		dest[x] = src[x];
		x++;
	}
	if (x < n)
	{
		y = x;
		while (y < n)
		{
			dest[y] = '\0';
			y++;
		}
	}
	return (h);
}
