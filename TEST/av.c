#include <stdio.h>

/**
 * main- Main
 * @ac: ac
 * @av: av
 * Return: value
 */

int main(int ac, char **av)
{
	(void)ac;
	while(*av)
	{
		printf("%s\n", *av);
		av++;
	}
	return (0);
}
