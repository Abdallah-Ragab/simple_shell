#include "main.h"

/**
 * getEnv - gets the value of an environ variable
 * @info: Structure containing potential arguments
 * @name: env var name
 * Return: the value
 */

char *getEnv(info_h *info, const char *name)
{
	list_h *node = info->env;
	char *x;

	while (node)
	{
		x = startsWith(node->str, name);
		if (x && *x)
		{
			return (x);
		}
		node = node->next;
	}
	return (NULL);
}
