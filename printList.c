#include "main.h"
/**
 * printList - prints all elements of a list_h linked list
 * @h: pointer
 * Return: size of list
 */
size_t printList(const list_h *h)
{
	size_t x = 0;

	while (h)
	{
		_puts(convertNumber(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		x++;
	}
	return (x);
}
