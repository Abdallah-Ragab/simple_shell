#include "main.h"

/**
 * deleteNodeAtIndex - deletes node at given index
 * @head: address of pointer
 * @index: index of node
 * Return: 1 or 0
 */

int deleteNodeAtIndex(list_h **head, unsigned int index)
{
	list_h *node, *prevNode;
	unsigned int x = 0;

	if (!head || !*head)
	{
		return (0);
	}
	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (x == index)
		{
			prevNode->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		x++;
		prevNode = node;
		node = node->next;
	}
	return (0);
}
