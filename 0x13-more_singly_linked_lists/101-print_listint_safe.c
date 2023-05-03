#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _r - rearrange memory for array of pointers
 * to the nodes in listint_t list
 * @list: previous list to append
 * @size: size of the new list
 * @new: new node for the list
 *
 * Return: pointer to the new list
 */
const listint_t **_r(const listint_t **list, size_t size, const listint_t *new)
{
	const listint_t **newlist;
	size_t x;

	newlist = malloc(size * sizeof(listint_t *));
	if (newlist == NULL)
	{
		free(list);
		exit(98);
	}
	for (x = 0; x < size - 1; x++)
		newlist[x] = list[x];
	newlist[x] = new;
	free(list);
	return (newlist);
}

/**
 * print_listint_safe - prints a listint_t safely.
 * @head: head pointer to start the list
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t x, numb = 0;
	const listint_t **list = NULL;

	while (head != NULL)
	{
		for (x = 0; x < numb; x++)
		{
			if (head == list[x])
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free(list);
				return (numb);
			}
		}
		numb++;
		list = _r(list, numb, head);
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
	}
	free(list);
	return (numb);
}
