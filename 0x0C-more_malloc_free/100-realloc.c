#include <stdlib.h>
#include "main.h"

/**
 * _realloc - reallocates a memory block with free malloc
 *
 * @ptr: pointer to the memory previously allocated by malloc
 * @old_size: size in bytes, of the allocated space for ptr
 * @new_size: new size, in bytes of the new memory block
 *
 * Return: pointer to allocate new size memory, or NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;
	unsigned int x, n = new_size;
	char *oldp = ptr;

	if (ptr == NULL)
	{
		p = malloc(new_size);
		return (p);
	}
	else if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (new_size == old_size)
		return (ptr);
	p = malloc(new_size);
	if (p == NULL)
		return (NULL);
	if (new_size > old_size)
		n = old_size;
	for (x = 0; x < n; x++)
		p[x] = oldp[x];
	free(ptr);
	return (p);
}
