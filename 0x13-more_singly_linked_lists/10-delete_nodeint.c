#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at certain index
 * @head: head pointer of the first element
 * @index: index node to the first element
 * Return: pointer to the index node
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int x;
	listint_t *tem, *next;

	if (head == NULL || *head == NULL)
		return (-1);
	if (index == 0)
	{
		next = (*head)->next;
		free(*head);
		*head = next;
		return (1);
	}
	tem = *head;
	for (x = 0; x < index - 1; x++)
	{
		if (tem->next == NULL)
			return (-1);
		tem = tem->next;
	}
	next = tem->next;
	tem->next = next->next;
	free(next);
	return (1);

}
