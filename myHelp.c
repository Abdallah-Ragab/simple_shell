#include "main.h"

/**
 * myHelp - changes the current directory of the process
 * @info: Structure containing potential arguments
 *  Return: 0
 */

int myHelp(info_h *info)
{
	char **argArray;

	argArray = info->argv;
	_puts("IM DEAD \n");
	if (0)
	{
		_puts(*argArray);
	}
	return (0);
}
