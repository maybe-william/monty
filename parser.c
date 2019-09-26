#include "monty.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * f1 - temporary function for instruction_t
 * @head: the head of the stack_t
 * @linum: the line number
 */
void f1(stack_t **head, unsigned int linum)
{
	(void)head;
	printf("%d\n", linum);
}

/**
 * get_op - get the struct with the info one at a time
 * @index: the index to get
 * Return: the struct with opcode and function to call
 */
instruction_t get_op(int index)
{
	static instruction_t ops[32];

	if ((ops[0]).opcode == NULL)
	{
		ops[0].opcode = "add";
		ops[1].opcode = "sub";
		ops[2].opcode = "div";
		ops[3].opcode = "mul";
		ops[4].opcode = "mod";
		ops[5].opcode = "pop";

		ops[6].opcode = "pall";
		ops[7].opcode = "pint";
		ops[8].opcode = "swap";
		ops[9].opcode = "pstr";
		ops[10].opcode = "rotl";
		ops[11].opcode = "rotr";

		ops[12].opcode = "pchar";
		ops[13].opcode = "stack";
		ops[14].opcode = "queue";
		/*TODO: fill all function pointers*/
		ops[0].f = add;
		ops[1].f = sub;
		ops[2].f = mydiv;
		ops[3].f = mul;
		ops[4].f = mod;
		ops[5].f = pop;
		ops[6].f = pall;
		ops[7].f = pint;
		ops[8].f = swap;
		ops[9].f = pstr;
		ops[10].f = rotl;
		ops[11].f = rotr;
		ops[12].f = pchar;
		ops[13].f = stack;
		ops[14].f = queue;

	}
	return (ops[index]);
}

/**
 * exec_push - do a push operation
 * @str: the line at the checkpoint
 * @head: the head of the stack
 * @linum: the current monty line number
 */
void exec_push(char *str, stack_t **head, int linum)
{
	int x = 0, digs = 0;
	char num[20] = {'\0'};

	if (strncmp(str, "push", 4) == 0)
	{
		while (*(str + 5 + digs) > 47 && *(str + 5 + digs) < 58)
			digs++;
		strncpy(num, str + 5, digs);
		x = atoi(num);
		if (x != -1 && digs != 0)
		{
			if (staq(0, 0))
				add_dnodeint(head, x);
			else
				add_dnodeint_end(head, x);
		}
		else
		{
			push_error(linum);
			last_status(-1);
			return;
		}
	}

}

/**
 * exec_comm - do a command for an opcode
 * @s: the string at a checkpoint
 * @head: the head of the stack
 * @linum: the monty line number
 */
void exec_comm(char *s, stack_t **head, int linum)
{
	int i = 0, l = 0;
	char inst[1024] = {'\0'};

	for (i = 0; i <= 5; i++)
	{
		if (strncmp(get_op(i).opcode, s, 3) == 0)
		{
			get_op(i).f(head, linum);
			return;
		}
	}
	for (i = 6; i <= 11; i++)
	{
		if (strncmp(get_op(i).opcode, s, 4) == 0)
		{
			get_op(i).f(head, linum);
			return;
		}

	}
	for (i = 12; i <= 14; i++)
	{
		if (strncmp(get_op(i).opcode, s, 5) == 0)
		{
			get_op(i).f(head, linum);
			return;
		}

	}
	if ((strncmp(s, "nop", 3) == 0) || (s[0] == '#'))
		return;
	if ((strncmp(s, "push", 4) == 0) || (s[0] == '\n') || (!(s[0])))
		return;
	while ((s[l] != '\n') && (s[l] != ' ') && (s[l] != 9) && (s[l]))
		l++;
	strncpy(inst, s, l);
	inst_error(inst, linum);
	last_status(-1);
}

/**
 * main - read each line from a file, parse, and execute on a stack/queue
 * @argc: the argv size
 * @argv: an array of command-line arguments to the program
 * Return: 0 if successful, -1 otherwise
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	int red = 0, linum = 1, stat = 0, i = 0;
	size_t length = 0;
	FILE *fd = NULL;
	stack_t *stack = NULL;

	fd = initialize_fd(argc, argv[1]);
	staq(1, 0);
	while (((red = getline(&line, &length, fd)) != -1) && stat != -1)
	{
		i = 0;

		while (line[i] == ' ' || line[i] == '	')
			i++;
		exec_push(line + i, &stack, linum);
		if (last_status(0))
		{
			stat = -1;
			break;
		}
		exec_comm(line + i, &stack, linum);
		if (last_status(0))
		{
			stat = -1;
			break;
		}
		linum++;
	}
	if (stat == 1)
		stat = 0;
	if (stat == -1)
		stat = 1;
	free(line);
	free_dlistint(stack);
	fclose(fd);
	if (stat)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}
