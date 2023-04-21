#include "variadic_functions.h"

/**
 * print_numbers - prints numbers followed by a new line
 * @n: number of parameter pased to the function
 * @separator: separate between numbers
 * Return: 0 (successful)
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int x;
	va_list ap;

	va_start(ap, n);

	if (separator == NULL)
		separator = "";

	for (x = 0; x < n; x++)
	{
		printf("%d", va_arg(ap, int));
		if (x < n - 1)
			printf("%s", separator);
	}
	printf("\n");
	va_end(ap);
}
