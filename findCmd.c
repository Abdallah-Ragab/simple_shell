#include "main.h"

/**
 * findCmd - find command
 * @info: the parameter
 * Return: void
 */

void findCmd(info_h *info)
{
	char *path = NULL;
	int x, y;

	info->path = info->argv[0];
	if (info->lineCountFlag == 1)
	{
		info->lineCount++;
		info->lineCountFlag = 0;
	}
	for (x = 0, y = 0; info->arg[x]; x++)
		if (!isDelim(info->arg[x], " \t\n"))
		{
			y++;
		}
	if (!y)
	{
		return;
	}

	path = findPath(info, getEnv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		forkCmd(info);
	}
	else
	{
		if ((interActive(info) || getEnv(info, "PATH=")
			|| info->argv[0][0] == '/') && isCmd(info, info->argv[0]))
			forkCmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			printError(info, "not found\n");
		}
	}
}
