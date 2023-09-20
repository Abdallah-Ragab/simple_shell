#include "main.h"

/**
 * unsetEnv - Remove an environment variable
 * @info: Structure containing potential arguments
 * @var: the string env var property
 * Return: 1 or 0
 */

int unsetEnv(info_h *info, char *var)
{
	list_h *node = info->env;
	size_t x = 0;
	char *y;

	if (!node || !var)
	{
		return (0);
	}

	while (node)
	{
		y = startsWith(node->str, var);
		if (y && *y == '=')
		{
			info->envChanged = deleteNodeAtIndex(&(info->env), x);
			x = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		x++;
	}
	return (info->envChanged);
}
