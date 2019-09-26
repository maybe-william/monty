#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * div_error - error message
 * @linum: the line number
 */
void div_error(unsigned int linum)
{
	char s[1024];

	sprintf(s, "L%u: can't div, stack too short\n", linum);
	error_mess(s);
}


/**
 * div_zero_error - error message
 * @linum: the line number
 */
void div_zero_error(unsigned int linum)
{
	char s[1024];

	sprintf(s, "L%u: division by zero\n", linum);
	error_mess(s);
}


/**
 * mul_error - error message
 * @linum: the line number
 */
void mul_error(unsigned int linum)
{
	char s[1024];

	sprintf(s, "L%u: can't mul, stack too short\n", linum);
	error_mess(s);
}


/**
 * mod_error - error message
 * @linum: the line number
 */
void mod_error(unsigned int linum)
{
	char s[1024];

	sprintf(s, "L%u: can't mod, stack too short\n", linum);
	error_mess(s);
}


/**
 * pchar_error - error message
 * @linum: the line number
 * @mode: error 1 or error 2
 */
void pchar_error(unsigned int linum, int mode)
{
	char s[1024];

	if (mode)
	{
		sprintf(s, "L%u: can't pchar, value out of range\n", linum);
		error_mess(s);
	}
	else
	{
		sprintf(s, "L%u: can't pchar, stack empty\n", linum);
		error_mess(s);
	}
}

