#include "lists.h"
/**
 * get_nodeint_at_index - this finds a given node in a linked list
 * @head : the pointer to the head of the linked list
 * @index: this is the index of the node to find (indices starting at 0)
 * Return: the pointer to the desired node,
 *         or returns NULL - if the node does not exist
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
size_t n;

for (n = 0; (n < index) && (head->next); n++)
head = head->next;

if (n < index)
return (NULL);

return (head);
}
