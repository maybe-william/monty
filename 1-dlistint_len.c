#include "monty.h"
/**
 * dlistint_len - returns the number of elements in dlistint_t list
 * @h: doubly linked list
 * Return: number of elements in list
 */
size_t dlistint_len(const dlistint_t *h)
{
	int i;

	for (i = 0; h != NULL; i++)
	{
		h = h->next;
	}
	return (i);
}
