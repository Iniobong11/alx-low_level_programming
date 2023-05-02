#include "lists.h"

/**
 * sum_listint - add all the data (n) of a listint_t linked list.
 * @head: first node pointer
 *
 * Return: addition
 */
int sum_listint(listint_t *head)
{
	int add = 0;

	while (head != NULL)
	{
		add += head->n;
		head = head->next;
	}
	return (add);
}
