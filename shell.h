#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

extern char **environ;

char *split(char *line, char **argv);
char *find_path_env(void);
char *search_in_path(char *path_env, char *path);
char *the_path(char *path);
int cmd(char **argv);
int built_exit(char **argv, char *str, char *line, int status);
int built_env(char **argv);
int built_c(char **argv);
int inbuilt(char **argv, char *str, char *line,int status);

#endif
