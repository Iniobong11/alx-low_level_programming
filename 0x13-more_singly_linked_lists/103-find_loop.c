#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list.
 * @head: pointer of the search linked list
 *
 * Return: address of the node where the loop starts, or NULL if no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *eagle, *square;

	eagle = square = head;
	while (eagle && square && square->next)
	{
		eagle = eagle->next;
		square = square->next->next;
		if (eagle == square)
		{
			eagle = head;
			break;
		}
	}
	if (!eagle || !square || !square->next)
		return (NULL);
	while (eagle != square)
	{
		eagle = eagle->next;
		square = square->next;
	}
	return (square);
}
