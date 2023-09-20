#include "main.h"

/**
 * listToStrings - returns an array of strings of the list->str
 * @head: pointer
 * Return: array of strings
 */

char **listToStrings(list_h *head)
{
	list_h *node = head;
	size_t x = listLen(head), y;
	char **strs;
	char *str;

	if (!head || !x)
	{
		return (NULL);
	}
	strs = malloc(sizeof(char *) * (x + 1));
	if (!strs)
	{
		return (NULL);
	}
	for (x = 0; node; node = node->next, x++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (y = 0; y < x; y++)
				free(strs[y]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[x] = str;
	}
	strs[x] = NULL;
	return (strs);
}
