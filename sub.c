#include "monty.h"

/**
 * sub - subtract two values on the stack
 * @head: the stack
 * @linum: the line number
 */
void sub(stack_t **head, unsigned int linum)
{
        int x = 0;
        int y = 0;
        int z = 0;

        if (!head || !(dlistint_len(*head) > 2))
        {
                sub_error(linum);
                last_status(-1);
                return;
        }

        x = get_dnodeint_at_index(*head, 0)->n;
        y = get_dnodeint_at_index(*head, 1)->n;
        z = x - y;
        get_dnodeint_at_index(*head, 1)->n = z;

        delete_dnodeint_at_index(head, 0);

}
