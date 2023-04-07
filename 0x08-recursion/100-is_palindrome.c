#include "main.h"
/**
 * _strlen_recursion - Print string length
 * @s: Printed string
 * Return: String length
 */
int _strlen_recursion(char *s)
{
	if (s[0] != '\0')
		return (1 + _strlen_recursion(s + 1));
	return (0);
}
/**
 * pal_confirm - confirm if s is a palindrome
 * @s: string address
 * @x: first index
 * @y: second index
 * Return: 1 if s is palindrome, otherwise 0
 */
int pal_confirm(char *s, int x, int y)
{
	if (s[x] == s[y])
		if (x > y / 2)
			return (1);
		else
			return (pal_confirm(s, x + 1, y - 1));
	else
		return (0);
}
/**
 * is_palindrome - Confirm if s is a palindrome
 * @s: string address
 *
 * Return: 1 if n is prime, otherwise 0
 */
int is_palindrome(char *s)
{
	return (pal_confirm(s, 0, _strlen_recursion(s) - 1));
}
