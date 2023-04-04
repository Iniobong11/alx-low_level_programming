#include "main.h"

/**
 * _strpbrk - function that searches a string for any of a set of bytes
 *
 * @s:first occurrence in the string
 * @accept: The set of btyes to be searched for
 *
 * Return: If a set is matched - a pointer to the matched btye.
 * If no set is matched - NULL.
 */
char *_strpbrk(char *s, char *accept)
{
	int i;
		while (*s)
		{
			for (i = 0; accept[i]; i++)
			{
				if (*s == accept[i])
					return (s);
			}
			s++;
		}
	return ('\0');
}
