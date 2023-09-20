#include "main.h"

/**
 * findPath - finds cmd in path string
 * @info: info struct
 * @pathstr: path string
 * @cmd: cmd to find
 * Return: full path of cmd or NULL
 */
char *findPath(info_h *info, char *pathstr, char *cmd)
{
	int x = 0, currPos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && startsWith(cmd, "./"))
	{
		if (isCmd(info, cmd))
		{
			return (cmd);
		}
	}
	while (1)
	{
		if (!pathstr[x] || pathstr[x] == ':')
		{
			path = dupChars(pathstr, currPos, x);
			if (!*path)
			{
				_strcat(path, cmd);
			}
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (isCmd(info, path))
			{
				return (path);
			}
			if (!pathstr[x])
			{
				break;
			}
			currPos = x;
		}
		x++;
	}
	return (NULL);
}
