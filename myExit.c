#include "main.h"

/**
 * myExit - exits the shell
 * Description: somthing
 * @info: Structure containing potential arguments
 * Return: exits with a given exit status
 */
int myExit(info_h *info)
{
	int exitcheck;

	if (info->argv[1])
	{
		exitcheck = erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			printError(info, "Illegal number: ");
			eputs(info->argv[1]);
			eputchar('\n');
			return (1);
		}
		info->errNum = erratoi(info->argv[1]);
		return (-2);
	}
	info->errNum = -1;
	return (-2);
}
