#include "main.h"

/**
 * set_bit - set the value of 1 bit to a given index.
 * @index: set the index of the bit to 1
 * @n: pointer number to change
 * Return: 1 if successful, or -1 if error occurrs
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int x;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	x = 1 << index;
	*n = *n | x;

	return (1);
}
