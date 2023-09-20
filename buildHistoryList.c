#include "main.h"

/**
 * buildHistoryList - adds entry to a history linked list
 * @info: Structure containing potential arguments
 * @buf: buffer
 * @linecount: the history linecount
 * Return: 0
 */

int buildHistoryList(info_h *info, char *buf, int linecount)
{
	list_h *node = NULL;

	if (info->history)
	{
		node = info->history;
	}
	addNodeEnd(&node, buf, linecount);

	if (!info->history)
	{
		info->history = node;
	}
	return (0);
}
