#include "main.h"

/**
 * dupChars - duplicates characters
 * @pathstr: path string
 * @start: starting index
 * @stop: stopping index
 * Return: pointer
 */

char *dupChars(char *pathstr, int start, int stop)
{
	static char buff[1024];
	int x = 0, y = 0;

	for (y = 0, x = start; x < stop; x++)
	{
		if (pathstr[x] != ':')
		{
			buff[y++] = pathstr[x];
		}
	}
	buff[y] = 0;
	return (buff);
}
