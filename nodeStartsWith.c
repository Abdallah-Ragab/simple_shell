#include "main.h"

/**
 * nodeStartsWith - returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string
 * @c: character
 * Return: NULL
 */
list_h *nodeStartsWith(list_h *node, char *prefix, char c)
{
	char *x = NULL;

	while (node)
	{
		x = startsWith(node->str, prefix);
		if (x && ((c == -1) || (*x == c)))
		{
			return (node);
		}
		node = node->next;
	}
	return (NULL);
}
