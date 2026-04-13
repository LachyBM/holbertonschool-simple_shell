#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern char **environ;

int main(int argc, char *argv[])
{
	char *path_env, *path_copy, *piece;
	int i = 1;
	int j = 0;
	char len[1024];

	if (argc < 2)
	{
		printf("Usage: %s \"string\"\n", argv[0]);
      		return (1);
    	}
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
		return (1);
	}
	while (i < argc)
	{
		path_copy = strdup(path_env);
		piece = strtok(path_copy, ":");

		while (piece != NULL)	
		{
			sprintf(len,"%s/%s", piece, argv[i]);

			if(access(len,X_OK) == 0)
				printf("%s\n", len);

			piece = strtok(NULL, ":");
		}
		
 	 free(path_copy);
	 i++;
	}
	return (0);
}
