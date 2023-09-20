#include "main.h"

/**
 * renumberHistory - renumbers the history linked list after changes
 * @info: Structure containing potential arguments
 * Return: new histcount
 */

int renumberHistory(info_h *info)
{
	list_h *node = info->history;
	int x = 0;

	while (node)
	{
		node->num = x++;
		node = node->next;
	}
	return (info->histcount = x);
}
