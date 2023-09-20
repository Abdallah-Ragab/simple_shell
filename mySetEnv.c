#include "main.h"

/**
 * mySetEnv - Initialize a new environment variable
 * @info: Structure containing potential arguments
 * Return: 0
 */

int mySetEnv(info_h *info)
{
	if (info->argc != 3)
	{
		eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (setEnv(info, info->argv[1], info->argv[2]))
	{
		return (0);
	}
	return (1);
}
