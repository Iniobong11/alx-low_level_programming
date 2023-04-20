#include "function_pointers.h"

/**
  * int_index - place return index if com = true, else -1
  * @array: array of elements
  * @size: size of array elements
  * @cmp: function pointer of one out of 3 main
  *
  * Return: 0 (successful)
  */
int int_index(int *array, int size, int (*cmp)(int))
{
	int x = 0;

	if (size > 0)
	{
		if (array != NULL && cmp != NULL)
		{
			while (x < size)
			{
				if (cmp(array[x]))
					return (x);

				x++;
			}
		}
	}
	return (-1);
}
