#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * _strlen - checks the length of a string
 * @str: find the length of a string
 *
 * Return: length of string
 */
unsigned int _strlen(char *str)
{
	unsigned int x;

	for (x = 0; str[x]; x++)
		;
	return (x);
}

/**
 * add_node_end - adds a new node to the close of linked list
 * @head: double pointer to a list_t
 * @str: new node to add to the string
 *
 * Return: pointer to the new node
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *nwn, *tmp;

	if (str == NULL)
		return (NULL);
	nwn = malloc(sizeof(list_t));
	if (nwn == NULL)
		return (NULL);
	nwn->str = strdup(str);
	if (nwn->str == NULL)
	{
		free(nwn);
		return (NULL);
	}
	nwn->len = _strlen(nwn->str);
	nwn->next = NULL;
	if (*head == NULL)
	{
		*head = nwn;
		return (nwn);
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = nwn;
	return (nwn);
}
