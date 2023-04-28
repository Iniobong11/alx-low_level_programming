#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * print_list - print codes of a linked list.
 * @h: pointer to the list_t to print
 * Return: the number of nodes.
 */
size_t print_list(const list_t *h)
{
	int record = 0;

	while (h)
	{
		if (h->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
		printf("[%d] %s\n", h->len, h->str);
		}
		record++;
		h = h->next;
	}
	return (record);
}
