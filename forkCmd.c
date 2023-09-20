#include "main.h"

/**
 * forkCmd - forks a an exec thread
 * @info: parameter again
 * Return: void
 */
void forkCmd(info_h *info)
{
	pid_t miniPid;

	miniPid = fork();
	if (miniPid == -1)
	{
		perror("Error:");
		return;
	}
	if (miniPid == 0)
	{
		if (execve(info->path, info->argv, getEnviron(info)) == -1)
		{
			freeInfo(info, 1);
			if (errno == EACCES)
			{
				exit(126);
			}
			exit(1);
		}
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				printError(info, "Permission denied\n");
		}
	}
}
