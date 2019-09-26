#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


/**
 * get_push_int - get the int to push or -1
 * @str: the start of the int parsing
 * Return: atoi of the num or -1
 */
int get_push_int(char *str)
{
	char s[20] = {'\0'};
	int off = 0, len = 0, pos = 1;

	while (str[off] == ' ' || str[off] == 9)
		off++;
	if (str[off] == '-')
	{
		off++;
		pos = 0;
	}

	while (str[off + len] > 47 && str[off + len] < 58)
		len++;
	if (!len)
		return (-1);
	if (!pos)
	{
		len = len + 1;
		off = off - 1;
	}
	strncpy(s, str + off, len);
	return (atoi(s));
}



/**
 * last_status - return the last status of command execution
 * @status: the status to set
 * Return: 0 if the last status was success, 1 otherwise
 */
int last_status(int status)
{
	static int stat;
	int temp = stat;

	stat = status;
	return (temp);
}


/**
 * error_mess - print an error message to stderr
 * @mess: the message to print
 */
void error_mess(char *mess)
{
	int len = 0;

	len = strlen(mess);
	write(STDERR_FILENO, mess, len);
}



/**
 * staq - switch between stack and queue and return which is
 * @s: stack
 * @q: queue
 * Return: the current state of stack/queue
 */
int staq(int s, int q)
{
	static int sq;

	if (s)
		sq = 1;
	else if (q)
		sq = 0;

	return (sq);
}

/**
 * initialize_fd - either throw an error and exit, or initialize the fd
 * @argc: the argcount
 * @filename: the filename
 * Return: the open fd if it worked
 */
FILE *initialize_fd(int argc, char *filename)
{
	char *memtest[10];
	int i = 0;
	FILE *ret = NULL;

	if (argc != 2)
	{
		argv_error();
		exit(EXIT_FAILURE);
	}

	ret = fopen(filename, "r");
	if (!ret)
	{
		file_error(filename);
		exit(EXIT_FAILURE);
	}


	for (i = 0; i < 10; i++)
		memtest[i] = malloc(1000);
	for (i = 0; i < 10; i++)
		if (memtest[i])
			free(memtest[i]);
		else
		{
			malloc_error();
			fclose(ret);
			exit(EXIT_FAILURE);
		}

	return (ret);
}
