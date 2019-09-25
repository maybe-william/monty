#include "lists.h"
/**
 * insert_dnodeint_at_index - function that inserts new node at given position
 * @h: first node of list
 * @idx: index of the list where the new node should be added
 * @n: data
 * Return: the address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new, *current = *h;
	unsigned int count = 0;

	if (*h == NULL && idx > 0)
	{
		return (NULL);
	}
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
	{
		return (NULL);
	}
	if (idx == 0)
	{
		new->n = n;
		new->next = *h;
		new->prev = NULL;
		if (*h)
			(*h)->prev = new;
		*h = new;
		return (new);
	}
	while (current)
	{
		if (count == idx - 1)
		{
			new->n = n;
			new->next = current->next;
			new->prev = current;
			if (new->next)
				(new->next)->prev = new;
			current->next = new;
			return (new);
		}
		current = current->next;
		count++;
	}
	free(new);
	return (NULL);
}
