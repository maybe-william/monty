#include "lists.h"
/**
 * sum_dlistint - function that returns the sum of all the data of linked list
 * @head: beginning of list
 * Return: sum of all the data (n)
 */
int sum_dlistint(dlistint_t *head)
{
	int sum;

	if (head)
	{
		sum = 0;
		while (head)
		{
			sum += head->n;
			head = head->next;
		}
		return (sum);
	}
	else
		return (0);
}
