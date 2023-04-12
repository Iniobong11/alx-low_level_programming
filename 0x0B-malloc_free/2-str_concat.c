#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * str_concat - addition of two strings.
 * @s1: first string concat
 * @s2: second string concat
 *
 * Return: a pointer to a newly allocated space in memory
 * of s1 and s2,terminate null. if the NULL fails
 */
char *str_concat(char *s1, char *s2)
{
	int x, y, len1, len2, len;
	char *result;

	len1 = len2 = 0;

	if (s1 != NULL)
	{
		x = 0;
		while (s1[x++] != '\0')
			len1++;
	}

	if (s2 != NULL)
	{
		x = 0;
		while (s2[x++] != '\0')
			len2++;
	}

	len = len1 + len2;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);

	for (x = 0; x < len1; x++)
		result[x] = s1[x];
	for (y = 0; y < len2; y++, x++)
		result[x] = s2[y];
	result[len] = '\0';

	return (result);
}
