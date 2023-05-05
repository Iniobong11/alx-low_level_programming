#include "main.h"

/**
 * clear_bit - sets the index value of a given bit to 0
 * @n: number of pointer to change
 * @index: bit index to clear
 * Return: 1 if successful, or -1 if error occurrs
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int x;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	x = ~(1 << index);
	*n = *n & x;

	return (1);
}
