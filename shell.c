#include "shell.h"


char *split(char *line, char **argv)
{
	char *str;
	char *piece;
	int i = 0;

	str = strdup(line);
	if (!str)
		return (NULL);
	piece = strtok(str, " \t\r\n\a");
	while (piece != NULL && i < 63)
	{
		argv[i++] = piece;
		piece = strtok(NULL, " \t\r\n\a");
	}
	argv[i] = NULL;
	return (str);
}

int cmd(char **argv)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child_pid == 0)
	{
		execve(argv[0], argv, environ);
		perror("Error:");
		exit(1);
	}
	wait(&status);
	return (0);
}

int main(void)
{
	ssize_t nread;
	size_t len = 0;
	char *line = NULL;
	char *argv[64];
	char *str;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("hsh$ ");
		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			free(line);
			return (0);
		}
		str = split(line, argv);
		if (argv[0] == NULL || str == NULL)
		{
			free(str);
			free(line);
			line = NULL;
			continue;
		}
		if (cmd(argv) == 1)
		{
			free(str);
			free(line);
			return (1);
		}
		free(str);
		free(line);
		line = NULL;
	}
	return (0);
}
