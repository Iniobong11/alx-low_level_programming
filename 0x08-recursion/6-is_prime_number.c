#include "main.h"

/**
 * confirm - confirm if the number is prime
 * @x: integer
 * @y: integer
 *
 * Return: integer
 */

int confirm(int x, int y)
{
	if (y < 2 || y % x == 0)
		return (0);
	else if (x > y / 2)
		return (1);
	else
		return (confirm(x + 1, y));
}

/**
 * is_prime_number - states if number is prime
 * @n:integer
 * Return:integer
 */
int is_prime_number(int n)
{
	if (n == 2)
		return (1);
	return (confirm(2, n));
}
