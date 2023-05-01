#include "lists.h"

/**
 * free_listint2 - function that frees a linked list
 * @head: pointer of lists to be freed
 *
 * Return: void
 */

void free_listint2(listint_t **head)
{
	listint_t *near;

	if (head == NULL)
		return;
	while (*head != NULL)
	{
		near = (*head)->next;
		free(*head);
		*head = near;
	}
}
