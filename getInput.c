#include "main.h"

/**
 * getInput - gets a line minus the newline
 * @info: parameter struct
 * Return: bytes read
 */

ssize_t getInput(info_h *info)
{
	static char *buf;
	static size_t x, y, len;
	ssize_t z = 0;
	char **buf_h = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	z = inputBuf(info, &buf, &len);
	if (z == -1)
		return (-1);
	if (len)
	{
		y = x;
		p = buf + x;

		checkChain(info, buf, &y, x, len);
		while (y < len)
		{
			if (isChain(info, buf, &y))
				break;
			y++;
		}

		x = y + 1;
		if (x >= len)
		{
			x = len = 0;
			info->cmdBufType = CMD_NORM;
		}

		*buf_h = p;
		return (_strlen(p));
	}

	*buf_h = buf;
	return (z);
}
