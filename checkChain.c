#include "main.h"

/**
 * checkChain - checks we should continue chaining based on last status
 * @info: parameter
 * @buf: char
 * @p: address
 * @i: starting position
 * @len: length of buf
 * Return: Void
 */

void checkChain(info_h *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t x = *p;

	if (info->cmdBufType == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			x = len;
		}
	}
	if (info->cmdBufType == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			x = len;
		}
	}

	*p = x;
}
