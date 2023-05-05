#include "main.h"
/**
 * get_endianness - search the endianness
 *
 * Return: 0 if large endian, 1 if small endian
 */
int get_endianness(void)
{
	int x;
	char *c;

	x = 1;
	c = (char *)&x;

	return (*c);
}
