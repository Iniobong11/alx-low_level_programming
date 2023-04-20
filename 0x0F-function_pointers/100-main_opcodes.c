#include <stdlib.h>
#include <stdio.h>

/**
 * print_opcodes - print the opcodes
 * @a: main function address
 * @n: print number of bytes
 *
 * Return: void
 */
void print_opcodes(char *a, int n)
{
	int x;

	for (x = 0; x < n; x++)
	{
		printf("%.2hhx", a[x]);
		if (x < n - 1)
			printf(" ");
	}
	printf("\n");

}

/**
 * main - prints its own opcodes of  main of the function
 * @argc: pass number of arguments to the function
 * @argv: array of arguments
 *
 * Return: always 0
 */
int main(int argc, char **argv)
{
	int n;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}
	n = atoi(argv[1]);
	if (n < 0)
	{
		printf("Error\n");
		exit(2);
	}
	print_opcodes((char *)&main, n);
	return (0);
}
