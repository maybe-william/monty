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
		ops[0].f = f1;
		ops[1].f = f1;
		ops[2].f = f1;
		ops[3].f = f1;
		ops[4].f = f1;
		ops[5].f = f1;
		ops[6].f = f1;
		ops[7].f = f1;
		ops[8].f = f1;
		ops[9].f = f1;
		ops[10].f = f1;
		ops[11].f = f1;
		ops[12].f = f1;
		ops[13].f = f1;
		ops[14].f = f1;

	}
	return (ops[index]);
}

/**
 * exec_push - do a push operation
 * @str: the line at the checkpoint
 * @head: the head of the stack
 * @linum: the current monty line number
 * Return: 0 if success, -1 if atoi fails (not pushing a number)
 */
int exec_push(char *str, stack_t **head, int linum)
{
	int x = 0, digs = 0;
	char num[20] = {'\0'};

	(void)head;
	if (strncmp(str, "push", 4) == 0)
	{
		while (*(str + 5 + digs) > 47 && *(str + 5 + digs) < 58)
			digs++;
		strncpy(num, str + 5, digs);
		x = atoi(num);
		if (x != -1)
		{
			printf("%d: PUSH %d\n", linum, x);
			/*add_dint_node(head, x)*/
		}
		else
		{
			return (-1);
		}
	}
	return (0);
}

/**
 * exec_comm - do a command for an opcode
 * @str: the string at a checkpoint
 * @head: the head of the stack
 * @linum: the monty line number
 * Return: 1 if success, 0 if nop or comment, -1 if error
 */
int exec_comm(char *str, stack_t **head, int linum)
{
	int i = 0;

	for (i = 0; i <= 5; i++)
	{
		if (strncmp(get_op(i).opcode, str, 3) == 0)
		{
			get_op(i).f(head, linum);
			return (1);
		}
	}
	for (i = 6; i <= 11; i++)
	{
		if (strncmp(get_op(i).opcode, str, 4) == 0)
		{
			get_op(i).f(head, linum);
			return (1);
		}

	}
	for (i = 12; i <= 14; i++)
	{
		if (strncmp(get_op(i).opcode, str, 5) == 0)
		{
			get_op(i).f(head, linum);
			return (1);
		}

	}
	if ((strncmp(str, "nop", 3) == 0) || (str[0] == '#'))
		return (0);
	if ((str[0] == '\n') || (!(str[0])))
		return (0);
	return (-1);
}

/**
 * main - read each line from a file, parse, and execute on a stack/queue
 * @argc: the argv size
 * @argv: an array of command-line arguments to the program
 * Return: 0 if successful, -1 otherwise
 */
int main(int argc, char **argv)
{
	char *line;
	int red = 0, linum = 1, stat = 0, i = 0;
	size_t length = 0;
	FILE *fd;
	stack_t *stack = NULL;

	(void)argc;
	fd = fopen(argv[1], "r");
	/*NULL check here*/
	while ((red = getline(&line, &length, fd)) != -1)
	{
		i = 0;

		while (line[i] == ' ' || line[i] == '	')
			i++;
		exec_push(line + i, &stack, linum);
		stat = exec_comm(line + i, &stack, linum);
		linum++;
	}
	fclose(fd);
	return (stat);
}
