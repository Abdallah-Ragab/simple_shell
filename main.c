#include "main.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 * Return: 0 or 1
 */

int main(int ac, char **av)
{
	info_h info[] = { INFO_INIT };
	int fd = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (fd)
			: "r" (fd));

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				eputs(av[0]);
				eputs(": 0: Can't open ");
				eputs(av[1]);
				eputchar('\n');
				eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	populateEnvList(info);
	readHistory(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}
