#include "main.h"

/**
 * erratoi - converts a string to an integer
 * @s: string
 * Return: 0 or -1
 */

int erratoi(char *s)
{
	int x = 0;
	unsigned long int result = 0;

	if (*s == '+')
	{
		s++;
	}
	while (s[x] != '\0')
	{
		if (s[x] >= '0' && s[x] <= '9')
		{
			result *= 10;
			result += (s[x] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
		{
			return (-1);
		}
		x++;
	}
	return (result);
}
