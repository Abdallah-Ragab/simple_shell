#include "main.h"

/**
 * myAlias - mimics the alias builtin
 * @info: Structure containing potential arguments
 *  Return: 0
 */

int myAlias(info_h *info)
{
	int x = 0;
	char *p = NULL;
	list_h *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			printAlias(node);
			node = node->next;
		}
		return (0);
	}
	for (x = 1; info->argv[x]; x++)
	{
		p = _strchr(info->argv[x], '=');
		if (p)
			setAlias(info, info->argv[x]);
		else
			printAlias(nodeStartsWith(info->alias, info->argv[x], '='));
	}

	return (0);
}
