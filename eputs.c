#include "main.h"

/**
 * eputs - prints an input string
 * @str: string
 * Return: Nothing stopeed
 */

void eputs(char *str)
{
	int x = 0;

	if (!str)
	{
		return;
	}
	while (str[x] != '\0')
	{
		eputchar(str[x]);
		x++;
	}
}
