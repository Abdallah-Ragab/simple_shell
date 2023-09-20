#include "main.h"

/**
 * printAlias - prints an alias string
 * @node: alias node
 * Return: 0 or 1
 */

int printAlias(list_h *node)
{
	char *x = NULL, *y = NULL;

	if (node)
	{
		x = _strchr(node->str, '=');
		for (y = node->str; y <= x ; y++)
			_putchar(*y);
		_putchar('\'');
		_puts(x + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}
