#include "monty.h"
/**
 * delete_dnodeint_at_index - deletes the node at index
 * @head: beginning of list
 * @index: index of the node that should be deleted
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	unsigned int i = 0;

	current = *head;
	if (*head == NULL)
		return (-1);
	else if (index == 0)
	{
		if ((*head)->next)
			((*head)->next)->prev = NULL;
		*head = (*head)->next;
		free(current);
	}
	else
	{
		while (i < index)
		{
			current = current->next;
			if (current == NULL)
				return (-1);
			i++;
		}
		if (current->next)
			(current->next)->prev = current->prev;
		(current->prev)->next = (current->next);
		free(current);
	}
	return (1);
}
