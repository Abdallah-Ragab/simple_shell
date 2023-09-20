#include "main.h"

/**
 * printError - prints an error message
 * @info: parameter
 * @estr: string
 * Return: 0 if no numbers in string
 */

void printError(info_h *info, char *estr)
{
	eputs(info->fname);
	eputs(": ");
	printDec(info->lineCount, STDERR_FILENO);
	eputs(": ");
	eputs(info->argv[0]);
	eputs(": ");
	eputs(estr);
}
