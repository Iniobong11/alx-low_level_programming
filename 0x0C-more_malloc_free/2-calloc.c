#include <stdlib.h>
#include "main.h"

/**
 * _calloc - allocates memory for an array @nmemb elements of
 * @size each element and returns a pointer to the allocated memory.
 *
 * @nmemb: number of elements in the array
 * @size: allocate size of element bytes
 *
 * Return: pointer to the allocated memory.
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *a;
	unsigned int x;

	if (nmemb == 0 || size == 0)
		return (NULL);
	a = malloc(nmemb * size);
	if (a == NULL)
		return (NULL);
	for (x = 0; x < (nmemb * size); x++)
		a[x] = 0;
	return (a);
}
