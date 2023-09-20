#include "main.h"

/**
 **_strchr - locates a character in a string
 *@s: string
 *@c: character
 *Return: pointer
 */

char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
		{
			return (s);
		}
	} while (*s++ != '\0');

	return (NULL);
}
