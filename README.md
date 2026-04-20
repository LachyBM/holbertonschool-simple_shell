# Holberton School - Simple Shell
This project is the culmination of our learning during the first trimester at Holberton School Australia. It builds on our knowledge of System Engineering, DevOps, Low-Level Programming and Algorithms. We have attempted to build our own Shell, using C programming language.

### Description
The shell is a program that takes commands from users and gives them to the operating system to perform. In addition to simple command line instructions, the shell can automate tasks using shell scripts; files containing a series of commands that will be read and carried out by the shell.

___
### Installation
You can  install the simple shell by cloning this repo:
```sh
git clone https://github.com/LachyBM/holbertonschool-simple_shell.git
```
You can compile the files with this command:
```sh
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
Lastly, you can run our shell with the following executable:
```sh
./hsh
```
### Output Examples
```sh
root@63bb13fab09146a795396ea95a351084-2377118072:~/holbertonschool-simple_shell# ./hsh
hsh$ ls -l
total 68
-rw-r--r-- 1 root root   142 Apr 20 06:08 AUTHORS
-rw-r--r-- 1 root root  1498 Apr 20 08:01 README.md
drwxr-xr-x 2 root root  4096 Apr 20 07:32 TEST
drwxr-xr-x 2 root root  4096 Apr 20 06:08 alpha
-rw-r--r-- 1 root root  1469 Apr 20 06:18 builtins.c
-rw-r--r-- 1 root root   733 Apr 20 06:15 exec.c
drwxr-xr-x 2 root root  4096 Apr 20 06:08 holder
-rwxr-xr-x 1 root root 17352 Apr 20 08:04 hsh
-rw-r--r-- 1 root root   571 Apr 20 06:08 man_1_simple_shell
-rw-r--r-- 1 root root   505 Apr 20 06:08 parser.c
-rw-r--r-- 1 root root  1523 Apr 20 06:08 path.c
-rw-r--r-- 1 root root   561 Apr 20 06:08 shell.h
-rw-r--r-- 1 root root   788 Apr 20 06:08 testshell.c
hsh$ 
```
```sh
root@63bb13fab09146a795396ea95a351084-2377118072:~/holbertonschool-simple_shell# ./hsh
hsh$ pwd
/root/holbertonschool-simple_shell
hsh$
```
```sh
root@63bb13fab09146a795396ea95a351084-2377118072:~/holbertonschool-simple_shell# ./hsh
hsh$ cat parser.c
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
hsh$
```

### Files
| File Name | Description |
| ------ | ------|
| main.c | Manages the execution loop of the shell. It handles user input, parses it into arguments, and determines whether to execute a built-in command or external program. Runs continuously, displaying a prompt in interactive mode, until an end-of-file condition or exit command in encountered.
| builtins.c | Implements the shell's built-in commands and the logic used to identify them. The file contains functions to handle commands such as exit, which terminates the shell, and env, which prints the current environment variables.
| exec.c | Handles the execution of external commands. The file contains the logic for creating child processes using fork, executing programes with execve, and synchronising with the parent process using wait.
| parser.c | Handles the parsing of user input into executable arguments. This file contains functions that tokenize the input string using delimiters such as spaces and newlines, converting it into an array of the arguments suitable for command execution. It also manages memory for the duplicated input string used during tokenization.
| path.c | Manages command path resolution using the system's environment variables. This file retrieves the PATH variable and searches through it's directories to locate executable commands. It determines whether a command should be executed using a direct path or by searching the PATH, and returns the full path to the executable if found.
| shell.h | Header file. Contains libraries and function prototypes.

### Built with
This project was built and developed with:
- 'C programming language:' is a general-purpose, procedural computer programming language that allows low-level access. All variables used must have a declared data type before it is used.
- 'Ubuntu 22.04 LTS:' Operating system, and tester.
- 'GCC:' GNU C Compiler version 11.4.0

## Authors
- Lachlan McKenna - Development and documentation
- Marcus Ryan - Development and documentation