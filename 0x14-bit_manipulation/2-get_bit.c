#include "main.h"

/**
 * get_bit - returns the value of a bit of an index number.
 * @n: number to check bits
 * @index: index of the bit
 *
 * Return: decimal value of the bit at index
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int bit, res;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	bit = 1 << index;
	res = n & bit;
	if (res == bit)
		return (1);

	return (0);
}
