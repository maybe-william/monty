#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * pint_error - error message
 * @linum: the line number
 */
void pint_error(unsigned int linum)
{
	char s[1024];

	sprintf(s, "L%u: can't pint, stack empty\n", linum);
	error_mess(s);
}

/**
 * pop_error - error message
 * @linum: the line number
 */
void pop_error(unsigned int linum)
{
	char s[1024];

	sprintf(s, "L%u: can't pop an empty stack\n", linum);
	error_mess(s);
}


/**
 * swap_error - error message
 * @linum: the line number
 */
void swap_error(unsigned int linum)
{
	char s[1024];

	sprintf(s, "L%u: can't swap, stack too short\n", linum);
	error_mess(s);
}


/**
 * add_error - error message
 * @linum: the line number
 */
void add_error(unsigned int linum)
{
	char s[1024];

	sprintf(s, "L%u: can't add, stack too short\n", linum);
	error_mess(s);
}


/**
 * sub_error - error message
 * @linum: the line number
 */
void sub_error(unsigned int linum)
{
	char s[1024];

	sprintf(s, "L%u: can't sub, stack too short\n", linum);
	error_mess(s);
}

