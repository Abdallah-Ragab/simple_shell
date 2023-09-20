#include "main.h"

/**
 * isAlpha - checks for alphabetic character
 * @c: character
 * Return: 1 if c is alphabetic, 0 otherwie
 */

int isAlpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
