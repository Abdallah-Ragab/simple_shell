#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>


/*read and write buffers*/
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/*command chaining*/
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/*convert_number*/
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/*1 when using system getline*/
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;

/**
 * struct liststr - singly linked
 * @num: number
 * @str: a string
 * @next: points to next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_h;

/**
 *struct passInfo - contains pseudo-arguements to pass into a function,
 *allowing uniform prototype for function pointer struct
 *@arg: arguements
 *@argv: array of strings
 *@path: string path for the current command
 *@argc: argument count
 *@lineCount: the error count
 *@errNum: error code
 *@lineCountFlag: count this line of input
 *@fname: program filename
 *@env: linked list
 *@environ: custom modified copy
 *@history: history node
 *@alias: alias node
 *@envChanged: on if environ was changed
 *@status: return status
 *@cmdBuf: address of pointer
 *@cmdBufType: CMD_type
 *@readfd: fd from which to read line input
 *@histcount: history line number count
 */
typedef struct passInfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int lineCount;
	int errNum;
	int lineCountFlag;
	char *fname;
	list_h *env;
	list_h *history;
	list_h *alias;
	char **environ;
	int envChanged;
	int status;

	char **cmdBuf;
	int cmdBufType;
	int readfd;
	int histcount;
} info_h;


#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtIn - contains a builtin string
 *@type: builtin command flag
 *@func: function
 */
typedef struct builtIn
{
	char *type;
	int (*func)(info_h *);
} builtinTable;

int hsh(info_h *, char **);
int findBuiltin(info_h *);
void findCmd(info_h *);
void forkCmd(info_h *);

int isCmd(info_h *, char *);
char *dupChars(char *, int, int);
char *findPath(info_h *, char *, char *);

void eputs(char *);
int eputchar(char);
int putfd(char c, int fd);
int putsfd(char *str, int fd);

int _strlen(char *);
int _strcmp(char *, char *);
char *startsWith(const char *, const char *);
char *_strcat(char *, char *);

char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

char **strTow(char *, char *);
char **str_Tow(char *, char);

char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

int bfree(void **);

int interActive(info_h *);
int isDelim(char, char *);
int isAlpha(int);
int _atoi(char *);

int erratoi(char *);
void printError(info_h *, char *);
int printDec(int, int);
char *convertNumber(long int, int, int);
void removeComments(char *);

int myExit(info_h *);
int myCd(info_h *);
int myHelp(info_h *);

int myHistory(info_h *);
int myAlias(info_h *);

ssize_t getInput(info_h *);
int getLine(info_h *, char **, size_t *);
void sigintHandler(int);

void clearInfo(info_h *);
void setInfo(info_h *, char **);
void freeInfo(info_h *, int);

char *getEnv(info_h *, const char *);
int myEnv(info_h *);
int mySetEnv(info_h *);
int myUnsetEnv(info_h *);
int populateEnvList(info_h *);

char **getEnviron(info_h *);
int unsetEnv(info_h *, char *);
int setEnv(info_h *, char *, char *);

char *getHistoryFile(info_h *info);
int writeHistory(info_h *info);
int readHistory(info_h *info);
int buildHistoryList(info_h *info, char *buf, int linecount);
int renumberHistory(info_h *info);

list_h *addNode(list_h **, const char *, int);
list_h *addNodeEnd(list_h **, const char *, int);
size_t printListStr(const list_h *);
int deleteNodeAtIndex(list_h **, unsigned int);
void freeList(list_h **);

size_t listLen(const list_h *);
char **listToStrings(list_h *);
size_t printList(const list_h *);
list_h *nodeStartsWith(list_h *, char *, char);
ssize_t getNodeIndex(list_h *, list_h *);

int isChain(info_h *, char *, size_t *);
void checkChain(info_h *, char *, size_t *, size_t, size_t);
int replaceAlias(info_h *);
int replaceVars(info_h *);
int replaceString(char **, char *);

ssize_t inputBuf(info_h *info, char **buf, size_t *len);
ssize_t readBuf(info_h *info, char *buf, size_t *i);
int printAlias(list_h *node);
int setAlias(info_h *info, char *str);
int unsetAlias(info_h *info, char *str);

#endif
