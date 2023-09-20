#include "main.h"

/**
 * readHistory - reads history from file
 * @info: parameter
 * Return: 0 or history count
 */

int readHistory(info_h *info)
{
	int x, last = 0, lineCount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buff = NULL, *fileName = getHistoryFile(info);

	if (!fileName)
		return (0);

	fd = open(fileName, O_RDONLY);
	free(fileName);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buff = malloc(sizeof(char) * (fsize + 1));
	if (!buff)
		return (0);
	rdlen = read(fd, buff, fsize);
	buff[fsize] = 0;
	if (rdlen <= 0)
		return (free(buff), 0);
	close(fd);
	for (x = 0; x < fsize; x++)
		if (buff[x] == '\n')
		{
			buff[x] = 0;
			buildHistoryList(info, buff + last, lineCount++);
			last = x + 1;
		}
	if (last != x)
		buildHistoryList(info, buff + last, lineCount++);
	free(buff);
	info->histcount = lineCount;
	while (info->histcount-- >= HIST_MAX)
		deleteNodeAtIndex(&(info->history), 0);
	renumberHistory(info);
	return (info->histcount);
}
