#include "lists.h"

/**
 * free_listint - this frees a linked list
 * @head: the head of the list
 *
 * Return: void return
 */
void free_listint(listint_t *head)
{
	listint_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
