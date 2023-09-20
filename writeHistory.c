#include "main.h"

/**
 * writeHistory - creates a file
 * @info: parameter
 * Return: 1 or -1
 */

int writeHistory(info_h *info)
{
	ssize_t fd;
	char *fileName = getHistoryFile(info);
	list_h *node = NULL;

	if (!fileName)
	{
		return (-1);
	}

	fd = open(fileName, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(fileName);
	if (fd == -1)
	{
		return (-1);
	}
	for (node = info->history; node; node = node->next)
	{
		putsfd(node->str, fd);
		putfd('\n', fd);
	}
	putfd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}
