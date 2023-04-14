#include "main.h"

/**
 * malloc_checked - allocates memory using malloc
 *
 * @b: allocated number of btyes
 *
 * Return: a pointer to the allocated number of memory
 */
void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);

	if (ptr == NULL)
		exit(98);

	return (ptr);
}
