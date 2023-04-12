#include "main.h"
#include <stdlib.h>

/**
 * create_array - create  array of chars and their sizes
 * @size: array size
 * @c: initial char value to assign
 *
 * Return: pointer to array, or if NULL fails
 */
char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int x;

	if (size == 0)
		return (NULL);

	array = (char *)malloc(sizeof(char) * size);
	if (array == NULL)
		return (NULL);

	for (x = 0; x < size; x++)
		array[x] = c;

	return (array);
}
