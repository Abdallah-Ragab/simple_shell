#include "main.h"

/**
 * hsh - main shell loop
 * @info: the parameter
 * @av: the argument vector
 * Return: 1 on error, 0 on success, or error code
 */

int hsh(info_h *info, char **av)
{
	ssize_t x = 0;
	int builtinRet = 0;

	while (x != -1 && builtinRet != -2)
	{
		clearInfo(info);
		if (interActive(info))
			_puts("$ ");
		_putchar(BUF_FLUSH);
		x = getInput(info);
		if (x != -1)
		{
			setInfo(info, av);
			builtinRet = findBuiltin(info);
			if (builtinRet == -1)
				findCmd(info);
		}
		else if (interActive(info))
			_putchar('\n');
		freeInfo(info, 0);
	}
	writeHistory(info);
	freeInfo(info, 1);
	if (!interActive(info) && info->status)
	{
		exit(info->status);
	}
	if (builtinRet == -2)
	{
		if (info->errNum == -1)
			exit(info->status);
		exit(info->errNum);
	}
	return (builtinRet);
}
