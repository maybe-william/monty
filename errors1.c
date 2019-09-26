#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * argv_error - error message
 */
void argv_error(void)
{
	error_mess("USAGE: monty file\n");
}

/**
 * file_error - error message
 * @file: the filename
 */
void file_error(char *file)
{
	char s[1024];

	sprintf(s, "Error: Can't open file %s\n", file);
	error_mess(s);
}

/**
 * inst_error - error message
 * @inst: the instruction
 * @linum: the line number
 */
void inst_error(char *inst, unsigned int linum)
{
	char s[1024];

	sprintf(s, "L%u: unknown instruction %s\n", linum, inst);
	error_mess(s);
}

/**
 * malloc_error - error message
 */
void malloc_error(void)
{
	error_mess("Error: malloc failed\n");
}

/**
 * push_error - error message
 * @linum: the line number
 */
void push_error(unsigned int linum)
{
	char s[1024];

	sprintf(s, "L%u: usage: push integer\n", linum);
	error_mess(s);
}

