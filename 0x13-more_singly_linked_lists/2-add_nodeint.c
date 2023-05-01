#include "lists.h"

/**
  * add_nodeint - add node at beginning of a listint_t.
  * @head: head of pointer to the first node
  * @n: insert int to the new node
  * Return: NULL if it fails
  */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *add;

	if (head == NULL)
		return (NULL);
	add = malloc(sizeof(listint_t));
	if (add == NULL)
		return (NULL);
	add->n = n;
	add->next = *head;
	*head = add;
	return (add);
}
