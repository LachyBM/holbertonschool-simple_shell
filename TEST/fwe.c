#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

extern char **environ;

int main(void)
{
	pid_t child_pid;
	int status;
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};
	int i = 0;

	while (i < 5)
	{
		child_pid = fork();
		if (child_pid == -1)
		{	
	  		perror("Error:");
       			return (1);
    		}
 		if (child_pid == 0)
    		{
        		printf("Child %d Pid:%d\n -ls -l /tmp  \n", i + 1, getpid());
			execve(argv[0], argv, environ);
			perror("Error:");
    			exit(99);
    		}
   		else
    		{
        		wait(&status);
        		printf("Child %d DONE ^^\n", i + 1); 
    		}
		i++;
	}
}
