#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;

int main(void)
{
	pid_t child_pid;
	int status;
	ssize_t nread;
	size_t len = 0;
	char *line;
	char *argv[2];
	int check;
	while (1)
	{
		line = NULL;
		if (isatty(STDIN_FILENO))
			printf("hsh$ ");
		nread = getline(&line, &len, stdin);
		if (nread == -1)
                {
                        free(line);        
                        return (0);
                }
		check = (int)strlen(line) - 1;
		while (check >= 0 && (line[check] == ' '  || line[check] == '\t' || line[check] == '\n' || line[check] == '\r'))
		{
			line[check--] = '\0';
		}
		if (check < 0)
			continue;
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
