#include "shell.h"

/**
 * main - entry point for the simple shell
 *
 * Description: reads user input, parses commands, executes built-ins
 * or external commands in a loop until exit or EOF.
 *
 * Return: exit status
 */

int main(void)
{
	ssize_t nread;
	size_t len = 0;
	char *line = NULL;
	char *argv[64];
	char *str;
	int status = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("hsh$ ");
		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			free(line);
			return (status);
		}
		str = split(line, argv);
		if (argv[0] == NULL || str == NULL)
		{
			free(str);
			free(line);
			line = NULL;
			continue;
		}
		status = inbuilt(argv, str, line, status);
		if (status == -1)
			status = cmd(argv);
		free(str);
		free(line);
		line = NULL;
	}
	return (status);
}
