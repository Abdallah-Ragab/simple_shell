#include "main.h"

/**
 * freeList - frees all nodes of a list
 * @head_ptr: address of pointer
 * Return: void
 */

void freeList(list_h **head_ptr)
{
	list_h *node, *nextNode, *head;

	if (!head_ptr || !*head_ptr)
	{
		return;
	}
	head = *head_ptr;
	node = head;
	while (node)
	{
		nextNode = node->next;
		free(node->str);
		free(node);
		node = nextNode;
	}
	*head_ptr = NULL;
}
