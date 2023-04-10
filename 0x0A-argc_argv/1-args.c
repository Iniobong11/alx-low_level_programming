#include <stdio.h>

/**
 * main - print the passed arguments in it
 * @argc: counting of arguments
 * @argv: argument in array
 *
 * Return: 0 (successful)
 */

int main(int argc, char **argv)
{
	(void)argv;

	printf("%d\n", argc - 1);
	return (0);
}
