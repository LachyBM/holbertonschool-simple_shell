#include "shell.h"

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

char *find_path_env(void)
{
  int j = 0;
  
while (environ[j])
	{
		if (strncmp(environ[j], "PATH=", 5) == 0)
		  return(environ[j] + 5);
		j++;	
	}
  return(NULL);
}

char *search_in_path (char *path_env, char *path)
{
        char *path_copy, *piece;
        char len[1024];

        path_copy = strdup(path_env);

	piece = strtok(path_copy, ":");
	while (piece)
	{
			sprintf(len,"%s/%s", piece, path);

			if(access(len, X_OK) == 0)
			{
				free(path_copy);
				return strdup(len);
			}
			piece = strtok(NULL, ":");
	}
		
 	free(path_copy);
	return (NULL);
}
  
char *the_path(char *path)
{
  char *path_env;

	if (!path)
		return (NULL);

	if (access(path,X_OK) == 0)
		return strdup(path);

	 path_env = find_path_env();
	if (!path_env)
	{
		printf("PATH NOT SET\n");
		return (NULL);
        }
	return (search_in_path(path_env, path));
}

int cmd(char **argv)
{
	pid_t child_pid;
	int status;
	char *path;

	path = the_path(argv[0]);
	if (!path)
	{
		fprintf(stderr,"./hsh: 1: %s: not found\n", argv[0]);
		return (127);
	}
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
	int status;

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
		status = cmd(argv);
		free(str);
		free(line);
		line = NULL;
	}
	return (status);
}
