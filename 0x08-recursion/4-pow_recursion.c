#include "main.h"

/**
 * _pow_recursion - power of a number
 * @a: integer
 * @b: integer
 *
 * Return: integer
 */

int _pow_recursion(int a, int b)
{
	if (b < 0)
	{
		return (-1);
	}
	else if (b != 0)
		return (a * _pow_recursion(a, b - 1));

	else
	{
		return (1);
	}
}
