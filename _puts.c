#include "main.h"

/**
 *_puts - prints an input string
 *@str: string to be printed
 * Return: Nothing :)
 */
void _puts(char *str)
{
	int x = 0;

	if (!str)
	{
		return;
	}
	while (str[x] != '\0')
	{
		_putchar(str[x]);
		x++;
	}
}
