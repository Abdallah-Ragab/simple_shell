#include "main.h"

/**
 * interActive - returns true if shell is interactive mode
 * @info: struct
 * Return: 1 if interactive mode, 0 otherwise
 */

int interActive(info_h *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
