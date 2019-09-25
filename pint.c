#include "pancakes.h"
/**
 * pint - prints the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	printf("%d\n", (*stack)->n);
}
