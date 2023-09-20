#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: destination buffer
 * @src: source buffer
 * Return: estination buffer pointer
 */

char *_strcat(char *dest, char *src)
{
	char *retur = dest;

	while (*dest)
	{
		dest++;
	}
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = *src;
	return (retur);
}
