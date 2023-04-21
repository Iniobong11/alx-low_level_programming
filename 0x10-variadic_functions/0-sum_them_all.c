#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - sum all the numbers
 * @n: number of passed parameters
 * @...: A variable number of paramters to calculate the sum of.
 *
 * Return: If n == 0 - 0.
 * Otherwise - the sum of all parameters.
 */

int sum_them_all(const unsigned int n, ...)
{
	va_list ap;
	unsigned int x, sum = 0;

	va_start(ap, n);

	for (x = 0; x < n; x++)
		sum += va_arg(ap, int);

	va_end(ap);

	return (sum);
}
