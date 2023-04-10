#include <stdio.h>
#include "main.h"

/**
 * main - Print the program name, then a new line
 * @argc: counting of arguments
 * @argv: argument array
 *
 * Return: 0 (sucessful)
 */

int main(int argc, char **argv)
{
	(void)argc;

	printf("%s\n", argv[0]);
	return (0);
}
