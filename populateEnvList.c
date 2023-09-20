#include "main.h"

/**
 * populateEnvList - populates env linked list
 * @info: Structure containing potential arguments
 * Return: 0
 */

int populateEnvList(info_h *info)
{
	list_h *node = NULL;
	size_t x;

	for (x = 0; environ[x]; x++)
	{
		addNodeEnd(&node, environ[x], 0);
	}
	info->env = node;
	return (0);
}
