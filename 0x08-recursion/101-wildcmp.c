#include "main.h"
/**
 * str_confirm - Compare if two strings are identical.
 * @s1: String_1 address
 * @s2: String_2 address
 * @x: left index
 * @y: personal indeex (fun)
 * Return: 1 if s is palindrome, otherwise 0
 */
int str_confirm(char *s1, char *s2, int x, int y)
{
	if (s1[x] == '\0' && s2[y] == '\0')
		return (1);
	if (s1[x] == s2[y])
		return (str_confirm(s1, s2, x + 1, y + 1));
	if (s1[x] == '\0' && s2[y] == '*')
		return (str_confirm(s1, s2, x, y + 1));
	if (s2[y] == '*')
		return (str_confirm(s1, s2, x + 1, y) || str_confirm(s1, s2, x, y + 1));
	return (0);
}
/**
 * wildcmp - Compare if strings could be considered identical
 * @s1: string_a address
 * @s2: string_b address
 *
 * Return: 1 if considered identical.
 */
int wildcmp(char *s1, char *s2)
{
	return (str_confirm(s1, s2, 0, 0));
}
