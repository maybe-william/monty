#include "monty.h"

/**
 * pstr - print the values on the stack as a string
 * @head: the stack
 * @linum: the line number
 */
void pstr(stack_t **head, unsigned int linum)
{
	int i;
	(void)linum;

	for (i = 0; (*head) != NULL; i++)
	{
		if ((*head)->n < 32 || (*head)->n > 127)
		{
			break;
		}
		printf("%c\n", (*head)->n);
		(*head) = (*head)->next;
	}
}
