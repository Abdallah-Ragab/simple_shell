#include "main.h"

/**
 * startsWith - checks if needle starts with haystack
 * @haystack: string
 * @needle: substring to find
 * Return: address of next char
 */

char *startsWith(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
		{
			return (NULL);
		}
	return ((char *)haystack);
}
