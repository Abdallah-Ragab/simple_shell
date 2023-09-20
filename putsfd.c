#include "main.h"

/**
 * putsfd - prints an input string
 * @str: string
 * @fd: filedescriptor
 * Return: number of chars
 */
int putsfd(char *str, int fd)
{
	int x = 0;

	if (!str)
	{
		return (0);
	}
	while (*str)
	{
		x += putfd(*str++, fd);
	}
	return (x);
}
