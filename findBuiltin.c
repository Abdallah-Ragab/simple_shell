#include "main.h"

/**
 * findBuiltin - find builtin command
 * @info: the parameter
 * Return: -1 if builtin not found,
 * 0 if builtin executed successfully or
 * 1 if builtin found but not successful or
 * -2 if builtin signals exit
 */

int findBuiltin(info_h *info)
{
	int x, builtInRet = -1;
	builtinTable builtintb[] = {
		{"exit", myExit},
		{"env", myEnv},
		{"help", myHelp},
		{"history", myHistory},
		{"setenv", mySetEnv},
		{"unsetenv", myUnsetEnv},
		{"cd", myCd},
		{"alias", myAlias},
		{NULL, NULL}
	};

	for (x = 0; builtintb[x].type; x++)
	{
		if (_strcmp(info->argv[0], builtintb[x].type) == 0)
		{
			info->lineCount++;
			builtInRet = builtintb[x].func(info);
			break;
		}
	}
	return (builtInRet);
}
