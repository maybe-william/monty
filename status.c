#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>







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
	write(stderr, mess, len);
}



/**
 * staq - switch between stack and queue and return which is
 * @s: stack
 * @q: queue
 * Return: the current state of stack/queue
 */
int staq(int s, int q)
{
	static sq;

	if (s)
		sq = 1;
	else if (q)
		sq = 0;

	return (sq);
}

