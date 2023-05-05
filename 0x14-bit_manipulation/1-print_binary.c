#include "main.h"
/**
 * _power - find the base and power
 * @base: base of the index
 * @pow: power of the index
 * Return: result of base and power
 */
unsigned long int _power(unsigned int base, unsigned int pow)
{
	unsigned long int num;
	unsigned int x;

	num = 1;
	for (x = 1; x <= pow; x++)
		num *= base;
	return (num);
}
/**
 * print_binary - prints the binary of a decimal number
 * @n: binary number to be printed
 * Return: void
 */
void print_binary(unsigned long int n)
{
	unsigned long int dev, result;
	char flag;

	flag = 0;
	dev = _power(2, sizeof(unsigned long int) * 8 - 1);

	while (dev != 0)
	{
		result = n & dev;
		if (result == dev)
		{
			flag = 1;
			_putchar('1');

		}
		else if (flag == 1 || dev == 1)
		{
			_putchar('0');
		}
		dev >>= 1;
	}
}
