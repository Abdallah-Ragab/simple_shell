#include "main.h"

/**
 * listLen - determines length of linked list
 * @h: pointer
 * Return: size of list
 */
size_t listLen(const list_h *h)
{
	size_t x = 0;

	while (h)
	{
		h = h->next;
		x++;
	}
	return (x);
}
