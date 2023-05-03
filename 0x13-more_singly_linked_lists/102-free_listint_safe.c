#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list.
 * @head: first head pointer to the list
 *
 * Return: number of nodes in the freed list
 */
size_t free_listint_safe(listint_t **h)
{
	size_t new = 0;
	int diff;
	listint_t *tem;
	
	if (!h || !*h)
		return (0);
	
	while (*h)
	{
		diff = *h - (*h)->next;
		if (diff > 0)
		{
			tem = (*h)->next;
			free(*h);
			*h = tem;
			new++;
		}
		else
		{
			free(*h);
			*h = NULL;
			new++;
			break;
		}
	}
	
	*h = NULL;
	
	return (new);
}
