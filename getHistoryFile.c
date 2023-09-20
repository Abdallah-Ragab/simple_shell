#include "main.h"

/**
 * getHistoryFile - gets the history file
 * @info: parameter
 * Return: buff
 */

char *getHistoryFile(info_h *info)
{
	char *buff, *dirr;

	dirr = getEnv(info, "HOME=");
	if (!dirr)
	{
		return (NULL);
	}
	buff = malloc(sizeof(char) * (_strlen(dirr) + _strlen(HIST_FILE) + 2));
	if (!buff)
	{
		return (NULL);
	}
	buff[0] = 0;
	_strcpy(buff, dirr);
	_strcat(buff, "/");
	_strcat(buff, HIST_FILE);
	return (buff);
}
