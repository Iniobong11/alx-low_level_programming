#include "main.h"

/**
 * flip_bits - flip to count tne num of bits to change.
 * @n: the first number
 * @m: the second number
 * Return: number of bits to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int x, calc = 0;
	unsigned long int present;
	unsigned long int exclusive = n ^ m;

	for (x = 63; x >= 0; x--)
	{
		present = exclusive >> x;
		if (present & 1)
			calc++;
	}

	return (calc);
}
