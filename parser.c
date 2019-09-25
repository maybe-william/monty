#include "holberton.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

instruction_t get_op(int index)
{
	static instruction_t ops[32];
	if ((ops[0]).opcode == NULL)
	{
		/*fill all values*/
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
	}
	return (ops[index]);
}

int exec_push(char *str, stack_t **head, int linum)
{
	int x = 0;

	if (strncmp(str, "push", 4) == 0)
	{
       		x = atoi(str + 5);
		if (x != -1)
		{
			add_dint_node(head, x)
		}
		else
		{
			return (-1);
		}
	}
	return (0);
}

int exec_comm(char *str, stack_t **head, int linum)
{
	for (i = 0; i <= 5; i++)
	{
		if (strncmp(get_op(i).opcode, str, 3) == 0)
		{
			f(head, linum);
			return (1);
		}
	}
	for (i = 6; i <= 11; i++)
	{
		if (strncmp(get_op(i).opcode, str, 4) == 0)
		{
			f(head, linum);
			return (1);
		}
	
	}
	for (i = 12; i<= 14; i++)
	{
		if (strncmp(get_op(i).opcode, str, 5) == 0)
		{
			f(head, linum);
			return (1);
		}
	
	}
	if ((strncmp(str, "nop", 3) == 0) || (str[0] == '#'))
		return (0);
	if ((str[0] == '\n') || (!(str[0])))
		return (0);
	return (-1);
}

int main(int argc, char **argv)
{
	char line[1024];
	int red = 0, linum = 1, stat = 0;
	size_t length = 0;
	FILE *fd;
	stack_t *stack = NULL;

	fd = fopen(argv[1], "r");
	/*NULL check here*/
	while ((red = getline(&line, &length, fd)) != -1)
	{
		i = 0;
		while (line[i])
		{
			while(line[i] == ' ' || line[i] == '	')
				i++;
			exec_push(line + i, &stack, linum);
			stat = exec_comm(line + i, &stack, linum);
			linum++;
			if (line[i] != '\0')
				i++;
		}

	}
	fclose(fd);
	return 0;
}
