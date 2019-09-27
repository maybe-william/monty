#include "monty.h"

/**
 * rotl - move top to end, second to top
 * @head: the stack
 * @linum: the line number
 */
void rotl(stack_t **head, unsigned int linum)
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

	t->next = h;
	h->prev = t;
	if (h->next)
	{
		h->next->prev = NULL;
		*head = h->next;
	}
	else
		*head = t;
	h->next = NULL;
}
