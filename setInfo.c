#include "main.h"

/**
 * setInfo - initializes info_h struct
 * @info: struct address
 * @av: argument vector
 * Return: void
 */

void setInfo(info_h *info, char **av)
{
	int x = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = strTow(info->arg, " \t");
		if (!info->argv)
		{

			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (x = 0; info->argv && info->argv[x]; x++)
			;
		info->argc = x;

		replaceAlias(info);
		replaceVars(info);
	}
}
