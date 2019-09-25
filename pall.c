#include "monty.h"
/**
 * pall - print all of the stack
 * @stack: pointer to stack
 * @line_number: line number
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	print_dlistint(*stack);
}
