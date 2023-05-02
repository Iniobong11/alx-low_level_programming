#include "lists.h"

/**
 * insert_nodeint_at_index - inserting a node in a new position
 * @head: first node pointer
 * @idx: index of the new node
 * @n: new node data value
 * Return: new node pointer, or NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int y;
	listint_t *tem, *new;

	if (head == NULL)
		return (NULL);
	if (idx != 0)
	{
		tem = *head;
		for (y = 0; y < idx - 1 && tem != NULL; y++)
		{
			tem = tem->next;
		}
		if (tem == NULL)
			return (NULL);
	}
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}
	new->next = tem->next;
	tem->next = new;
	return (new);
}
