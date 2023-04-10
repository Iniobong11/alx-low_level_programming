#include <stdio.h>

/**
 * main - print the recieved arguments
 * @argc: counting of arguments
 * @argv: array of arguments
 *
 * Return: 0 (successful)
 *
 */

int main(int argc, char **argv)
{
	int a;

	for (a = 0; a < argc; a++)
		printf("%s\n", argv[a]);

	return (0);
}
