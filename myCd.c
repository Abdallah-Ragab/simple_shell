#include "main.h"

/**
 * myCd - changes the current directory of the process
 * @info: Structure containing potential arguments
 *  Return: 0
 */
int myCd(info_h *info)
{
	char *x, *dir, buffer[1024];
	int chdirRet;

	x = getcwd(buffer, 1024);
	if (!x)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = getEnv(info, "HOME=");
		if (!dir)
			chdirRet = /* TODO: IDK */
				chdir((dir = getEnv(info, "PWD=")) ? dir : "/");
		else
			chdirRet = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!getEnv(info, "OLDPWD="))
		{
			_puts(x);
			_putchar('\n');
			return (1);
		}
		_puts(getEnv(info, "OLDPWD=")), _putchar('\n');
		chdirRet = /* TODO: idkk*/
			chdir((dir = getEnv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdirRet = chdir(info->argv[1]);
	if (chdirRet == -1)
	{
		printError(info, "can't cd to ");
		eputs(info->argv[1]), eputchar('\n');
	}
	else
	{
		setEnv(info, "OLDPWD", getEnv(info, "PWD="));
		setEnv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
