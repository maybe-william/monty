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

	if (!stack || !(*stack))
	{
		pop_error(line_number);
		last_status(-1);
		return;
	}


	*stack = (*stack)->next;
	free(hold);
}
