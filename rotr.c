#include "monty.h"

/**
 * rotr - rotate the bottom of the stack to the top
 * @head: the stack
 * @linum: the line number
 */
void rotr(stack_t **head, unsigned int linum)
{
	stack_t *h = NULL;
	stack_t *t = NULL;

	(void)linum;
	if (!head || !(*head))
		return;
	t = *head;
	while (t->next)
		t = t->next;
	h = *head;

	h->prev = t;
	t->next = h;
	if (t->prev)
		t->prev->next = NULL;
	*head = t;
	t->prev = NULL;
}
