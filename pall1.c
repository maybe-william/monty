#include "monty.h"
/**
 * pall -  print all of the stack
 * @head: pointer to head
 * @linnum: line number
 * Return: void
 */
void pall(stack_t **head, unsigned int linum)
{
	(void)linum;
	print_dlistint(*head);
}
