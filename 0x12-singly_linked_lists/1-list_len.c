#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * list_len - print the number of codes in a linked list .
 * @h: pointer of the list_t print
 * Return: the number of nodes in h.
 */
size_t list_len(const list_t *h)
{
	int rec = 0;

	while (h)
	{
		rec++;
		h = h->next;
	}
	return (rec);
}
