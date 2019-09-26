#include "monty.h"

/**
 * swap - swap two values on the stack
 * @head: the stack
 * @linum: the line number
 */
void swap(stack_t **head, unsigned int linum)
{
	int x = 0;
	int y = 0;

	if (!head || !(dlistint_len(*head) > 2))
	{
		swap_error(linum);
		last_status(-1);
		return;
	}

	x = get_dnodeint_at_index(*head, 0)->n;
	y = get_dnodeint_at_index(*head, 1)->n;

	y = get_dnodeint_at_index(*head, 0)->n;
	y = get_dnodeint_at_index(*head, 1)->n;
}
