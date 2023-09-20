#include "main.h"

/**
 * replaceAlias - replaces an aliases in the tokenized string
 * @info: parameter
 * Return: 1 or 0
 */

int replaceAlias(info_h *info)
{
	int x;
	list_h *node;
	char *p;

	for (x = 0; x < 10; x++)
	{
		node = nodeStartsWith(info->alias, info->argv[0], '=');
		if (!node)
		{
			return (0);
		}
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
		{
			return (0);
		}
		p = _strdup(p + 1);
		if (!p)
		{
			return (0);
		}
		info->argv[0] = p;
	}
	return (1);
}
