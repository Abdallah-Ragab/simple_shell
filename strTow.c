#include "main.h"

/**
 * **strTow - splits a string into words. Repeat delimiters are ignored
 * @str: input string
 * @d: delimeter string
 * Return: pointer or NULL on failure
 */

char **strTow(char *str, char *d)
{
	int x, y, s, n, numwords = 0;
	char **h;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (x = 0; str[x] != '\0'; x++)
		if (!isDelim(str[x], d) && (isDelim(str[x + 1], d) || !str[x + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	h = malloc((1 + numwords) * sizeof(char *));
	if (!h)
		return (NULL);
	for (x = 0, y = 0; y < numwords; y++)
	{
		while (isDelim(str[x], d))
			x++;
		s = 0;
		while (!isDelim(str[x + s], d) && str[x + s])
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
