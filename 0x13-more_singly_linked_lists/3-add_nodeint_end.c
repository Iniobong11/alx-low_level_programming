#include "lists.h"

/**
  * add_nodeint_end - add node at end of a listint_t
  * @head: head pointer to the first element
  * @n: add int in the new element list
  * Return: NULL if it failed
  */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *add;
	listint_t *tem;

	if (head == NULL)
		return (NULL);
	add = malloc(sizeof(listint_t));
	if (add == NULL)
		return (NULL);
	add->n = n;
	add->next = NULL;
	if (*head == NULL)
	{
	*head = add;
		return (add);
	}
	tem = *head;
	while (tem->next != NULL)
	{
		tem = tem->next;
	}
	tem->next = add;
	return (add);
}
