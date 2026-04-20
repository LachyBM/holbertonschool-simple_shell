#include "shell.h"

/**
 * built_exit - handles the exit built-in command
 * @argv: array of arguments
 * @str: duplicated input string
 * @line: original input line
 * @status:
 *
 * Return: does not return (exits the program)
 */

int built_exit(char **argv, char *str, char *line, int status)
{
int statusj = status;
if (argv[1] != NULL)
  statusj = (int)strtol(argv[1], NULL, 10);
	free(str);
	free(line);
	exit(statusj);
}

/**
 * built_env - print the environment variables
 * @argv: array of arguments (unused)
 *
 * Return: 0 on success
 */

int built_env(char **argv)
{
	unsigned int i = 0;
	(void)argv;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}

/**
 * built_c - handles Ctrl+C input (placeholder)
 * @argv: array of arguments (unused)
 *
 * Return: always 0
 */

int built_c(char **argv)
{
	(void)argv;
	return (0);
}

/**
 * inbuilt - checks and executes built-in commands
 * @argv: array of arguments
 * @str: duplicated input string
 * @line: original input line
 *
 * Return: result of built-in function, or -1 if not a built-in
 */

int inbuilt(char **argv, char *str, char *line, int status)
{
	if (strcmp(argv[0], "exit") == 0)
	  return (built_exit(argv, str, line, status));
	if (strcmp(argv[0], "env") == 0)
		return (built_env(argv));
	if (strcmp(argv[0], "^C") == 0)
		return (built_c(argv));
	return (-1);
}
