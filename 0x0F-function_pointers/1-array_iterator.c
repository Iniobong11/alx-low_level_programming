#include "function_pointers.h"

/**
 * array_iterator - prints given function as array element
 * on a new line.
 *
 * @array: execute array function
 * @size: print size of the array elem
 * @action: pointer to the function in regular or hex
 *
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t x;

	if (array && action)
	{
		x = 0;
		while (x < size)
		{
			action(array[x]);
			x++;
		}
	}
}
