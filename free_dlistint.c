#include "monty.h"

/**
 * free_dlistint - Frees a stack_t list.
 *
 * @head: Head of list.
 */

void free_dlistint(stack_t *head)
{
	stack_t *temp;

	temp = head;

	if (!head)
		return;

	while (1)
	{
		temp = head->next;
		free(head);
		if (!temp)
			return;
		head = temp->next;
		free(temp);
		if (!head)
			return;
	}
}
