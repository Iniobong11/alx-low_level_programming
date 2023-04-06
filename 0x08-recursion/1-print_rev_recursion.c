#include "main.h"

/**
 * _print_rev_recursion - Prints a string in the reverse other
 * @s: string
 * Return: 0 (successful)
 */

void _print_rev_recursion(char *s)
{
	if (*s)
	{
		_print_rev_recursion(s + 1);
		_putchar(*s);
	}
}
