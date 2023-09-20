#include "main.h"

/**
 * replaceVars - replaces vars in the tokenized string
 * @info: parameter
 * Return: 1 or 0
 */

int replaceVars(info_h *info)
{
	int x = 0;
	list_h *node;

	for (x = 0; info->argv[x]; x++)
	{
		if (info->argv[x][0] != '$' || !info->argv[x][1])
		{
			continue;
		}

		if (!_strcmp(info->argv[x], "$?"))
		{
			replaceString(&(info->argv[x]),
				_strdup(convertNumber(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[x], "$$"))
		{
			replaceString(&(info->argv[x]),
				_strdup(convertNumber(getpid(), 10, 0)));
			continue;
		}
		node = nodeStartsWith(info->env, &info->argv[x][1], '=');
		if (node)
		{
			replaceString(&(info->argv[x]),
				_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replaceString(&info->argv[x], _strdup(""));
	}

	return (0);
}
