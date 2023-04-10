#include <stdio.h>
#include "main.h"

/**
 * main - prinnt recieved arguments
 * @argc: counting of arguments
 * @argv: argument in array
 *
 * Return: 0 (successful)
 */

int main(int argc, char **argv)
{
	int a;

	for (a = 0; a < argc; a++)
		printf("%s\n", argv[a]);

	return (0);
}
