#include "lists.h"
#include <stdio.h>

/**
 * print_listint - prints all the elements of a listint_t
 *
 * @h: head of linklist to be printed
 *
 * Return: number of nodes
 *
 */
size_t print_listint(const listint_t *h)
{
	size_t numb = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		numb++;
	}
	return (numb);
}