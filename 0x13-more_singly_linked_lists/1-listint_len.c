#include "lists.h"

/**
 * listint_len - Number of elements in a linked listint_t.
 *
 * @h: head pointer type listint_t to transverse
 *
 * Return: the number of nodes
 *
 */

size_t listint_len(const listint_t *h)
{
	size_t rec = 0;

	while (h != NULL)
	{
	h = h->next;
		rec++;
	}
	return (rec);
}
