#include "lists.h"

/**
 * free_listint - frees a listint_t list
 *
 * @head: head of the list to be freed
 *
 * Return: NULL if error
 */

void free_listint(listint_t *head)
{
	listint_t *near;

	while (head != NULL)
	{
		near = head->next;
		free(head);
		head = near;
	}
}
