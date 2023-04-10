#include <stdio.h>
#include <stdlib.h>

/**
 * main - Adding positive integers
 * @argc: counting of arguments
 * @argv: array of arguments
 *
 * Return: 0 (successful)
 */
int main(int argc, char **argv)
{
	int x, n, sum = 0;
	char *flag;

	if (argc < 2)
	{
		printf("0\n");
		return (0);
	}

	for (x = 1; argv[x]; x++)
	{
		n = strtol(argv[x], &flag, 10);
		if (*flag)
		{
			printf("Error\n");
			return (1);
		}
		else
		{
			sum += n;
		}
	}
	printf("%d\n", sum);

	return (0);
}
