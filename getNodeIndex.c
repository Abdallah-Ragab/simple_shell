#include "main.h"

/**
 * getNodeIndex - gets the index of a node
 * @head: pointer
 * @node: pointer
 * Return: -1
 */

ssize_t getNodeIndex(list_h *head, list_h *node)
{
	size_t x = 0;

	while (head)
	{
		if (head == node)
		{
			return (x);
		}
		head = head->next;
		x++;
	}
	return (-1);
}
