#include "main.h"

/**
 * putfd - writes the character c to given fd
 * @c: character
 * @fd: The filedescriptor
 * Return: On success 1 or -1 on fail
 */
int putfd(char c, int fd)
{
	static int x;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(fd, buf, x);
		x = 0;
	}
	if (c != BUF_FLUSH)
	{
		buf[x++] = c;
	}
	return (1);
}
