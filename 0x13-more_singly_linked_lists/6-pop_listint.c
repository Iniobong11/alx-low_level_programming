#include "lists.h"

/**
 * pop_listint - deletes the head node of listint_t
 * @head: head pointer of the first link
 *
 *Return: empty
 */
int pop_listint(listint_t **head)
{
 listint_t *tem;
 int begin;

 if (!head || !*head)
 return (0);

 begin = (*head)->n;
 tem = (*head)->next;
 free(*head);
 *head = tem;

 return (begin);
}
