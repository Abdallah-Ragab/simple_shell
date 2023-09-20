#include "main.h"

/**
 * getLine - gets the next line of input from STDIN
 * @info: parameter struct
 * @ptr: address of pointer to buffer
 * @length: size of preallocated ptr buffer
 * Return: integer
 */

int getLine(info_h *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t x, len;
	size_t y;
	ssize_t z = 0, s = 0;
	char *p = NULL, *new_h = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (x == len)
		x = len = 0;

	z = readBuf(info, buf, &len);
	if (z == -1 || (z == 0 && len == 0))
		return (-1);

	c = _strchr(buf + x, '\n');
	y = c ? 1 + (unsigned int)(c - buf) : len;
	new_h = _realloc(p, s, s ? s + y : y + 1);
	if (!new_h)
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_h, buf + x, y - x);
	else
		_strncpy(new_h, buf + x, y - x + 1);

	s += y - x;
	x = y;
	p = new_h;

	if (length)
		*length = s;
	*ptr = p;
	return (s);
}
