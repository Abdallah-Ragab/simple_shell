#include "main.h"

/**
 * removeComments - function replaces first instance of '#' with '\0'
 * @buf: address
 * Return: void
 */
void removeComments(char *buf)
{
	int x;

	for (x = 0; buf[x] != '\0'; x++)
		if (buf[x] == '#' && (!x || buf[x - 1] == ' '))
		{
			buf[x] = '\0';
			break;
		}
}
