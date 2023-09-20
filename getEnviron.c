#include "main.h"

/**
 * getEnviron - returns the string array copy of our environ
 * @info: Structure containing potential arguments
 * Return: 0
 */

char **getEnviron(info_h *info)
{
	if (!info->environ || info->envChanged)
	{
		info->environ = listToStrings(info->env);
		info->envChanged = 0;
	}

	return (info->environ);
}
