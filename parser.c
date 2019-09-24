#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>

instruction_t get_op(int index)
{
	static instruction_t ops[32];
	if ((ops[0]).opcode == NULL)
	{
		/*fill all values*/
		ops[0].opcode = "pall";
		ops[1].opcode = "pint";
		ops[2].opcode = "pop";
		ops[3].opcode = "swap";
		ops[4].opcode = "add";
		ops[5].opcode = "sub";
		ops[6].opcode = "div";
		ops[7].opcode = "mul";
		ops[8].opcode = "mod";
		ops[9].opcode = "pchar";
		ops[10].opcode = "pstr";
		ops[11].opcode = "rotl";
		ops[12].opcode = "rotr";
		ops[13].opcode = "stack";
		ops[14].opcode = "queue";
		/*TODO: fill all function pointers*/
	}
	return (ops[index]);
}
int exec_push(char *str, int linum)
{
	/*if str == push*/
       		/*if num is good*/
			/*push num*/
		/*else*/
			/*error and exit*/

}

int exec_comm(char *str, int linum)
{
	/*if str == any of the commands */
		/*run the command function*/
		/*return 1*/
	/*if str is an empty line, comment, or nop*/
		/*return 0*/
	/*return -1*/

}

int main(int argc, char **argv)
{
	char line[1024];
	int red = 0, linum = 1, stat = 0;
	size_t length = 0;
	FILE *fd;

	fd = fopen(argv[1], "r");
	/*NULL check here*/
	while ((red = getline(&line, &length, fd)) != -1)
	{
		i = 0;
		while (line[i])
		{
			while(line[i] == ' ' || line[i] == '	')
				i++;
			exec_push(line + i, linum);
			stat = exec_comm(line + i, linum);
			linum++;
			if (line[i] != '\0')
				i++;
		}

	}
	fclose(fd);
	return 0;
}
