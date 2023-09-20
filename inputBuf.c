#include "main.h"

/**
 * inputBuf - buffers chained commands
 * @info: parameter struct
 * @buf: address of buffer
 * @len: address of len var
 * Return: bytes
 */

ssize_t inputBuf(info_h *info, char **buf, size_t *len)
{
	ssize_t x = 0;
	size_t len_h = 0;

	if (!*len)
	{
		/*bfree((void **)info->cmd_buf);*/
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		x = getLine(buf, &len_h, stdin);
#else
		x = getLine(info, buf, &len_h);
#endif
		if (x > 0)
		{
			if ((*buf)[x - 1] == '\n')
			{
				(*buf)[x - 1] = '\0';
				x--;
			}
			info->lineCountFlag = 1;
			removeComments(*buf);
			buildHistoryList(info, *buf, info->histcount++);
			if (_strchr(*buf, ';'))
			{
				*len = x;
				info->cmdBuf = buf;
			}
		}
	}
	return (x);
}
