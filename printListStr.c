#include "main.h"

/**
 * printListStr - prints only the str element of a list_h linked list
 * @h: pointer
 * Return: size of list
 */

size_t printListStr(const list_h *h)
{
	size_t x = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		x++;
	}
	return (x);
}
