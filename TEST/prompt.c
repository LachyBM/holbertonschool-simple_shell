#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	int nread;

	while(nread != -1)
	{
		printf("$ ");
		nread = getline(&line, &len, stdin);
		printf("%s", line);
	}
	free(line);
	return (0);
}
