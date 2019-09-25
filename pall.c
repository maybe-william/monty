#include "monty.h"
/**
 * pall - print all of the stack
 * @stack: pointer to stack
 * @line_number: line number
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *traverse = *stack;
	(void)line_number;
	for (; traverse; traverse = traverse->next)
		printf("%d\n", traverse->n);
}
