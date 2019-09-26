#include "monty.h"

/**
 * queue - change the stack into a queue
 * @head: the stack
 * @linum: the line number
 */
void queue(stack_t **head, unsigned int linum)
{
	(void)head;
	(void)linum;
	staq(0, 1);
}
