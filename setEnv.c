#include "main.h"

/**
 * setEnv - Initialize a new environment variable
 * @info: Structure containing potential arguments
 * @var: the string env var property
 * @value: the string env var value
 * Return: 0
 */

int setEnv(info_h *info, char *var, char *value)
{
	char *buff = NULL;
	list_h *node;
	char *x;

	if (!var || !value)
	{
		return (0);
	}

	buff = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buff)
	{
		return (1);
	}
	_strcpy(buff, var);
	_strcat(buff, "=");
	_strcat(buff, value);
	node = info->env;
	while (node)
	{
		x = startsWith(node->str, var);
		if (x && *x == '=')
		{
			free(node->str);
			node->str = buff;
			info->envChanged = 1;
			return (0);
		}
		node = node->next;
	}
	addNodeEnd(&(info->env), buff, 0);
	free(buff);
	info->envChanged = 1;
	return (0);
}
