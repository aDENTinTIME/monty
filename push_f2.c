#include "monty.h"

/**
 * push_f - Adds a new node at the end of a stack_t list.
 *
 * @stack: Head of list.
 * @n: Number to be stored in node.
 * Return: Pointer to new node.
 */

void push_f(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *slow, *fast;

	slow = *stack;
	fast = *stack;

	if (!stack)
		return;

	new = malloc(sizeof(stack_t));
	if (!new)
		return;

	if (*stack == NULL)
	{
		*stack = new;
		new->n = atoi(code_line[1]);
		new->next = NULL;
		new->prev = NULL;
		return;
	}

	fast = fast->next;
	while (fast)
	{
		fast = fast->next;
		slow = slow->next;
	}

	new->n = atoi(code_line[1]);
	new->next = fast;
	new->prev = slow;

	if (new->next != NULL)
		new->next->prev = new;

	slow->next = new;
}
