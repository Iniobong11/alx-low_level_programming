#include "lists.h"

/**
 * get_nodeint_at_index - the nth node of a certain linked list.
 * @head: pointer of the first node linked list
 * @index: index of the return node
 *
 * Return: pointer of index or NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int x;

	if (head == NULL)
		return (NULL);
	for (x = 0; x < index; x++)
	{
		head = head->next;
		if (head == NULL)
			return (NULL);
	}
	return (head);
}
