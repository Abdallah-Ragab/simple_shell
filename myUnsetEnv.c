#include "main.h"

/**
 * myUnsetEnv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 * Return: 0
 */

int myUnsetEnv(info_h *info)
{
	int x;

	if (info->argc == 1)
	{
		eputs("Too few arguements.\n");
		return (1);
	}
	for (x = 1; x <= info->argc; x++)
	{
		unsetEnv(info, info->argv[x]);
	}

	return (0);
}
