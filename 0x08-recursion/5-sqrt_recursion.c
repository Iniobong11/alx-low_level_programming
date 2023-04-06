#include "main.h"

/**
 * confirm - confirm the square root
 * @x: integer
 * @y: integer
 *
 * Return: integer
 */

int confirm(int x, int y)
{
	if (x * x == y)
		return (x);
	if (x * x > y)
		return (-1);
	return (confirm(x + 1, y));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: integer to find sqrt of
 * Return: natural square root or -1
 */
int _sqrt_recursion(int n)
{
	if (n == 0)
		return (0);
	return (confirm(1, n));
}
