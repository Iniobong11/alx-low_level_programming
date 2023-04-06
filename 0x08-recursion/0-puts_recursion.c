#include "main.h"

/**
 * _puts_recursion - Puts function with recursion;
 * @s: string input
 * Return: 0 (sucessful)
 */

void _puts_recursion(char *s)
{
	if (*s)
	{
		_putchar(*s);
		_puts_recursion(s + 1);
	}

	else
		_putchar('\n');
}
