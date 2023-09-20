#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: string
 * Return: 0 if no numbers in string
 */

int _atoi(char *s)
{
	int x = 0, sign = 1, flag = 0, output;
	unsigned int result = 0;

	while (s[x] != '\0' && flag != 2)
	{
		if (s[x] == '-')
			sign *= -1;

		if (s[x] >= '0' && s[x] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[x] - '0');
		}
		else if (flag == 1)
		{
			flag = 2;
		}
		x++;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
