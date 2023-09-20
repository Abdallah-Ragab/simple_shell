#include "main.h"

/**
 * setAlias - sets alias to string
 * @info: parameter
 * @str: string alias
 * Return: 0 or 1
 */

int setAlias(info_h *info, char *str)
{
	char *x;

	x = _strchr(str, '=');
	if (!x)
	{
		return (1);
	}
	if (!*++x)
	{
		return (unsetAlias(info, str));
	}

	unsetAlias(info, str);
	return (addNodeEnd(&(info->alias), str, 0) == NULL);
}
