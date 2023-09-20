#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: character
 * Return: On success 1 or -1 on fail :(
 */

int _putchar(char c)
{
	static int x;
	static char buff[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(1, buff, x);
		x = 0;
	}
	if (c != BUF_FLUSH)
	{
		buff[x++] = c;
	}
	return (1);
}
