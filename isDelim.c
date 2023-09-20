#include "main.h"

/**
 * isDelim - checks if character is a delimeter
 * @c: char
 * @delim: delimeter
 * Return: 1 if true, 0 if false
 */

int isDelim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}
