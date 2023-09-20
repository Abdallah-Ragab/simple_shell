#include "main.h"

/**
 * clearInfo - initializes info_h struct
 * @info: struct address
 * Return: void
 */

void clearInfo(info_h *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}
