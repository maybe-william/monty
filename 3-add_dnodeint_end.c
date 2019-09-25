#include "monty.h"
/**
 * add_dnodeint_end - adds a new node at the end of a list_t list
 * @head: beginning of list
 * @n: int to be added to head
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *end = *head;
	dlistint_t *new = NULL;

	new = malloc(sizeof(dlistint_t));
	if (!new)
	{
		return (NULL);
	}
	new->n = n;
	new->next = NULL;
	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}
	while (end->next != NULL)
		end = end->next;
	end->next = new;
	new->prev = end;

	return (new);
}
