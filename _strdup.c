#include "main.h"

/**
 * _strdup - duplicates a string
 * @str: string to duplicate
 * Return: pointer to the duplicated string
 */

char *_strdup(const char *str)
{
	int len = 0;
	char *retur;

	if (str == NULL)
	{
		return (NULL);
	}
	while (*str++)
	{
		len++;
	}
	retur = malloc(sizeof(char) * (len + 1));
	if (!retur)
	{
		return (NULL);
	}
	for (len++; len--;)
	{
		retur[len] = *--str;
	}
	return (retur);
}
