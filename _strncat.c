#include "main.h"

/**
 **_strncat - concatenates two strings
 *@dest: 1st string
 *@src: 2nd string
 *@n: amount of bytes
 *Return: concatenated string
 */

char *_strncat(char *dest, char *src, int n)
{
	int x = 0, y = 0;
	char *h = dest;

	while (dest[x] != '\0')
	{
		x++;
	}
	while (src[y] != '\0' && y < n)
	{
		dest[x] = src[y];
		x++;
		y++;
	}
	if (y < n)
	{
		dest[x] = '\0';
	}
	return (h);
}
