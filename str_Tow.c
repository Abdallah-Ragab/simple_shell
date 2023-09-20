#include "main.h"

/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow2(char *str, char d)
{
	int x, y, s, n, numwords = 0;
	char **h;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (x = 0; str[x] != '\0'; x++)
		if ((str[x] != d && str[x + 1] == d) ||
		    (str[x] != d && !str[x + 1]) || str[x + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	h = malloc((1 + numwords) * sizeof(char *));
	if (!h)
		return (NULL);
	for (x = 0, y = 0; y < numwords; y++)
	{
		while (str[x] == d && str[x] != d)
			x++;
		s = 0;
		while (str[x + s] != d && str[x + s] && str[x + s] != d)
			s++;
		h[y] = malloc((s + 1) * sizeof(char));
		if (!h[y])
		{
			for (s = 0; s < y; s++)
				free(h[s]);
			free(h);
			return (NULL);
		}
		for (n = 0; n < s; n++)
			h[y][n] = str[x++];
		h[y][n] = 0;
	}
	h[y] = NULL;
	return (h);
}
