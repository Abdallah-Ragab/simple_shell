#include "main.h"

/**
 * freeInfo - frees info_h struct fields
 * @info: struct address
 * @all: true if freeing all fields
 * Return: void
 */

void freeInfo(info_h *info, int all)
{
	ffree(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->cmdBuf)
		{
			free(info->arg);
		}
		if (info->env)
		{
			freeList(&(info->env));
		}
		if (info->history)
		{
			freeList(&(info->history));
		}
		if (info->alias)
		{
			freeList(&(info->alias));
		}
		ffree(info->environ);
			info->environ = NULL;
		bfree((void **)info->cmdBuf);
		if (info->readfd > 2)
		{
			close(info->readfd);
		}
		_putchar(BUF_FLUSH);
	}
}
