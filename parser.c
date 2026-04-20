#include "shell.h"

/**
 * split - splits a line into tokens (arguments)
 * @line: input string from user
 * @argv: array to store parsed arguments
 *
 * Return: pointer to a duplicated string, or NULL if failure
 */

char *split(char *line, char **argv)
{
	char *str, *piece;
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
