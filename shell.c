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

char *the_path(char *path)
{
	char *path_env, *path_copy, *piece;
	int j = 0;
	char len[1024];

	if (!path)
		return (NULL);

	if (access(path,X_OK) == 0)
		return strdup(path);
	/**
	 * walks through environ for PATH=
	 * if not exit
	 */ 
	while (environ[j])
	{
		if (strncmp(environ[j], "PATH=", 5) == 0)
		{
			path_env = environ[j] + 5;
			break;
		}
		j++;
	}
	
	if (!path_env)
	{
		printf("PATH NOT SET\n");
		return (NULL);
	}
	path_copy = strdup(path_env);
	piece = strtok(path_copy, ":");
	while (piece)
	{
			sprintf(len,"%s/%s", piece, path);

			if(access(len,X_OK) == 0)
			{
				free(path_copy);
				return strdup(len);
			}
			piece = strtok(NULL, ":");
	}
		
 	free(path_copy);
	return (NULL);
}

int cmd(char **argv)
{
	pid_t child_pid;
	int status;
	char *path;

	path = the_path(argv[0]);
	if (!path)
		return (1);
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		free(path);
		return (1);
	}
	if (child_pid == 0)
	{
		execve(path, argv, environ);
		perror("Error:");
		free(path);
		exit(1);
	}
	wait(&status);
	free(path);
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
