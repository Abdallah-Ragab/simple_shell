#include "main.h"

/**
 * myHistory - displays the history list
 * @info: Structure containing potential arguments
 *  Return: 0
 */

int myHistory(info_h *info)
{
	printList(info->history);
	return (0);
}
