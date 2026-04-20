#include "shell.h"

/**
 * find_path_env - retrieves the PATH environment variable
 *
 * Return: pointer to PATH value or NULL if not found
 */

char *find_path_env(void)
{
	int j = 0;

	while (environ[j])
	{
		if (strncmp(environ[j], "PATH=", 5) == 0)
			return (environ[j] + 5);
		j++;
	}
	return (NULL);
}

/**
 * search_in_path - searches for a command in the PATH directories
 * @path_env: PATH environment variable string
 * @path: command to search for
 *
 * Return: full path to command if found, or NULL if not found
 */

char *search_in_path(char *path_env, char *path)
{
	char *path_copy, *piece;
	char len[1024];

	path_copy = strdup(path_env);
	piece = strtok(path_copy, ":");

	while (piece)
	{
		sprintf(len, "%s/%s", piece, path);
		if (access(len, X_OK) == 0)
		{
			free(path_copy);
			return (strdup(len));
		}
		piece = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}

/**
 * the_path - resolves the full path of the command
 * @path: command name or path
 *
 * Descriptions: If the command contains '/', it is treated as a direct path.
 * Otherwise, it searches for the command in the PATH environment variable.
 *
 * Return: full path to executable or NULL if not found.
 */

char *the_path(char *path)
{
	char *path_env;

	if (!path)
		return (NULL);

	if (strchr(path, '/'))
	{
	if (access(path, X_OK) == 0)
		return (strdup(path));
	return (NULL);
	}

		path_env = find_path_env();
	if (!path_env || path_env[0] == '\0')
	{
		return (NULL);
	}
	return (search_in_path(path_env, path));
}
