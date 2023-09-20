#include "main.h"

/**
 * eputchar - writes the character c to stderr
 * @c: character
 * Return: On success 1 or -1 if error
 */
int eputchar(char c)
{
	static int x;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(2, buf, x);
		x = 0;
	}
	if (c != BUF_FLUSH)
	{
		buf[x++] = c;
	}
	return (1);
}
