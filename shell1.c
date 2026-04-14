#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

extern char **environ;

int main(void)
{
	pid_t child_pid;
	int status;
	ssize_t nread;
	size_t len = 0;
	char *line = NULL;
	char *argv[2];

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
	
		while (nread >= 0 && line[nread - 1] == '\n')
			line[nread - 1] = '\0';
		
		while (nread >= 0 && line[nread - 2] == ' ')
		{
			line[nread - 2] = '\0';
			nread--;
		}

		argv[0] = line;
		argv[1] = NULL;

		child_pid = fork();
		if (child_pid == -1)
		{	
	  		perror("Error:");
			free(line);
       			return (1);
    		}
 		if (child_pid == 0)
    		{
			execve(argv[0], argv, environ);
			perror("Error:");
			free(line);
    			exit(1);
    		}
   		else
    		{
        		wait(&status);
    		}
		
	}
	free(line);
	return (0);
	
}
