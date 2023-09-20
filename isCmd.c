#include "main.h"

/**
 * isCmd - if a file is an executable
 * @info: info struct
 * @path: path
 * Return: 1 or 0
 */

int isCmd(info_h *info, char *path)
{
	struct stat ht;

	(void)info;
	if (!path || stat(path, &ht))
	{
		return (0);
	}
	if (ht.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}
