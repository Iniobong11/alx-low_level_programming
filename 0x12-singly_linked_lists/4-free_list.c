#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_list - free the memory of a linked list
 *
 * @head: A pointer list_t list to be freed
 */

void free_list(list_t *head)
{
	if (head)
	{
		free_list(head->next);
		if (head->str)
			free(head->str);
		free(head);
	}
}
