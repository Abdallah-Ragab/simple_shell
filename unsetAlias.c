#include "main.h"

/**
 * unsetAlias - sets alias to string
 * @info: parameter
 * @str: string alias
 * Return: 0 or 1
 */

int unsetAlias(info_h *info, char *str)
{
	char *x, y;
	int ret;

	x = _strchr(str, '=');
	if (!x)
	{
		return (1);
	}
	y = *x;
	*x = 0;
	ret = deleteNodeAtIndex(&(info->alias),
		getNodeIndex(info->alias, nodeStartsWith(info->alias, str, -1)));
	*x = y;
	return (ret);
}
