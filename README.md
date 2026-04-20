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
total 96
-rw-r--r-- 1 root root   737 Apr 20 06:08 '#exec.c#'
-rw-r--r-- 1 root root  2553 Apr 20 06:08 '#testshell.c#'
-rw-r--r-- 1 root root   142 Apr 20 06:08  AUTHORS
-rw-r--r-- 1 root root  1498 Apr 20 07:24  README.md
drwxr-xr-x 2 root root  4096 Apr 20 06:08  TEST
drwxr-xr-x 2 root root  4096 Apr 20 06:08  alpha
-rw-r--r-- 1 root root  1469 Apr 20 06:18  builtins.c
-rw-r--r-- 1 root root   733 Apr 20 06:15  exec.c
drwxr-xr-x 2 root root  4096 Apr 20 06:08  holder
-rwxr-xr-x 1 root root 17352 Apr 20 07:25  hsh
-rw-r--r-- 1 root root   571 Apr 20 06:08  man_1_simple_shell
-rw-r--r-- 1 root root   505 Apr 20 06:08  parser.c
-rw-r--r-- 1 root root  1523 Apr 20 06:08  path.c
-rw-r--r-- 1 root root   561 Apr 20 06:08  shell.h
-rwxr-xr-x 1 root root 17136 Apr 20 06:08  testing
-rw-r--r-- 1 root root   788 Apr 20 06:08  testshell.c
```

### Files
| File Name | Description |
| ------ | ------|
|  |
|  |

### Built with
This project was built and developed with:
- 'C programming language:' is a general-purpose, procedural computer programming language that allows low-level access. All variables used must have a declared data type before it is used.
- 'Ubuntu 22.04 LTS:' Operating system, and tester.
- 'GCC:' GNU C Compiler version 11.4.0

## Authors
- Lachlan McKenna - Development and documentation
- Marcus Ryan - Development and documentation