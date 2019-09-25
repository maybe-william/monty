#include "monty.h"
/**
 * pop - removes the top element of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *hold = *stack;
	(void)line_number;
	*stack = (*stack)->next;
	free(hold);
}
