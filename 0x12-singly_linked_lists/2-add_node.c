#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * _strlen - function that returns the length of a string.
 * @s : s is a character
 * Return: value is x
 */
int _strlen(const char *s)
{
	int x = 0;

	while (s[x] != '\0')
	{
		x++;
	}
	return (x);
}

/**
 * add_node - add a new node at the start of a list_t
 * @head: double pointer of a list_t
 * @str: new string to insert into element.
 * Return: the number of nodes, or NULL if it fails
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *plus;

	plus = malloc(sizeof(list_t));
	if (plus == NULL)
		return (NULL);
	plus->str = strdup(str);

	plus->len = _strlen(str);
	plus->next = *head;
	*head = plus;

	return (plus);
}
