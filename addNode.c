#include "main.h"

/**
 * add_node - adds a node to the start of the list
 * @head: address of pointer
 * @str: str
 * @num: node index
 * Return: size of list
 */

list_h *addNode(list_h **head, const char *str, int num)
{
	list_h *newHead;

	if (!head)
	{
		return (NULL);
	}
	newHead = malloc(sizeof(list_h));
	if (!newHead)
	{
		return (NULL);
	}
	_memset((void *)newHead, 0, sizeof(list_h));
	newHead->num = num;
	if (str)
	{
		newHead->str = _strdup(str);
		if (!newHead->str)
		{
			free(newHead);
			return (NULL);
		}
	}
	newHead->next = *head;
	*head = newHead;
	return (newHead);
}
