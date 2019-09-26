#include "monty.h"
/**
 * pint - prints the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		pint_error(line_number);
		last_status(-1);
		return;
	}


	printf("%d\n", (*stack)->n);
}
