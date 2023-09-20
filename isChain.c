#include "main.h"

/**
 * isChain - test if current char in buffer is a chain delimeter
 * @info: parameter
 * @buf: buffer
 * @p: address
 * Return: 1 or 0
 */
int isChain(info_h *info, char *buf, size_t *p)
{
	size_t x = *p;

	if (buf[x] == '|' && buf[x + 1] == '|')
	{
		buf[x] = 0;
		x++;
		info->cmdBufType = CMD_OR;
	}
	else if (buf[x] == '&' && buf[x + 1] == '&')
	{
		buf[x] = 0;
		x++;
		info->cmdBufType = CMD_AND;
	}
	else if (buf[x] == ';')
	{
		buf[x] = 0;
		info->cmdBufType = CMD_CHAIN;
	}
	else
	{
		return (0);
	}
	*p = x;
	return (1);
}
