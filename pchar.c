#include "monty.h"

/**
 * pchar - print the top value on the stack as a character
 * @head: the stack
 * @linum: the line number
 */
void pchar(stack_t **head, unsigned int linum)
{
	if (!head)
	{
		pchar_error(linum, 1);
		last_status(-1);
		return;
	}

	if (((*head)->n < 32) || ((*head)->n > 127))
	{
		pchar_error(linum, 0);
		last_status(-1);
		return;
	}

	printf("%c\n", (*head)->n);
}
