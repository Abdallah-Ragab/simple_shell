#include "main.h"

/**
 * myEnv - prints the current environment
 * @info: Structure containing potential arguments
 * Return: 0
 */

int myEnv(info_h *info)
{
	printListStr(info->env);
	return (0);
}
