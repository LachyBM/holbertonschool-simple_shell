#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;

/**
 * trim_line - trims trailing and leading whitespace from a line
 * @line: the string to trim
 *
 * Return: pointer to first non-whitespace char, or NULL if line is empty.
 */
char *trim_line(char *line)
{
	char *start;
	int i;

	i = (int)strlen(line) - 1;
	while (i >= 0 && (line[i] == ' ' || line[i] == '\t'
		|| line[i] == '\n' || line[i] == '\r'))
		line[i--] = '\0';
	start = line;
	while (*start == ' ' || *start == '\t' || *start == '\r')
		start++;
	if (*start == '\0')
		return (NULL);
	return (start);
}

/**
 * run_command - forks and executes a command
 * @cmd: the command string to execute
 *
 * Return: 0 on success, 1 on fork error.
 */
int run_command(char *cmd)
{
	char *argv[2];
	pid_t child_pid;
	int status;

	argv[0] = cmd;
	argv[1] = NULL;
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

/**
 * main - entry point for simple shell
 *
 * Return: 0 on success, 1 on error.
 */
int main(void)
{
	ssize_t nread;
	size_t len = 0;
	char *line = NULL;
	char *start;

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
		start = trim_line(line);
		if (start == NULL)
		{
			free(line);
			line = NULL;
			continue;
		}
		if (run_command(start) == 1)
		{
			free(line);
			return (1);
		}
		free(line);
		line = NULL;
	}
	return (0);
}
