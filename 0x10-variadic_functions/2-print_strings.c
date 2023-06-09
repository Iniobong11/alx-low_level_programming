#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_strings - Prints strings passed to the function, new line
 * @separator: string used to separate strings
 * @n: number of passed string parameters
 * @...: A variable number of strings to be printed.
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	char *str;
	unsigned int x;
	va_list ap;

	va_start(ap, n);
	if (separator == NULL)
		separator = "";

	for (x = 0; x < n; x++)
	{
		str = va_arg(ap, char*);
		if (str == NULL)
			str = "(nil)";
		printf("%s", str);
		if (x < n - 1)
			printf("%s", separator);
	}
	printf("\n");
	va_end(ap);
}
