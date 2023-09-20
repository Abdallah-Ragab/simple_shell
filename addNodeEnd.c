#include "main.h"

/**
 * addNodeEnd - add a node to the end of the list
 * @head: address
 * @str: str field
 * @num: node index
 * Return: size of list
 */

list_h *addNodeEnd(list_h **head, const char *str, int num)
{
	list_h *newNode, *node;

	if (!head)
	{
		return (NULL);
	}

	node = *head;
	newNode = malloc(sizeof(list_h));
	if (!newNode)
	{
		return (NULL);
	}
	_memset((void *)newNode, 0, sizeof(list_h));
	newNode->num = num;
	if (str)
	{
		newNode->str = _strdup(str);
		if (!newNode->str)
		{
			free(newNode);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = newNode;
	}
	else
		*head = newNode;
	return (newNode);
}
