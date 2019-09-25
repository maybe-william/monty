#include "lists.h"
/**
 * free_dlistint - frees a dlistint_t list
 * @head: beginning of list
 * Return: void
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *holder;

	while (head)
	{
		holder = head;
		head = head->next;
		free(holder);
	}
}
