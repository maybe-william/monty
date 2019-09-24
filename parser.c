#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>


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
			exec_push(line + i);
			stat = exec_comm(line + i, linum);
			linum++;
			if (line[i] != '\0')
				i++;
		}

	}
	fclose(fd);
	return 0;
}
