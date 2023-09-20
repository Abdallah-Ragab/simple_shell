#include "main.h"

/**
 * readBuf - reads a buffer
 * @info: parameter struct
 * @buf: buffer
 * @i: size
 * Return: z
 */

ssize_t readBuf(info_h *info, char *buf, size_t *i)
{
	ssize_t z = 0;

	if (*i)
		return (0);
	z = read(info->readfd, buf, READ_BUF_SIZE);
	if (z >= 0)
		*i = z;
	return (z);
}
