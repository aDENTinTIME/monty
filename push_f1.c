#include "monty.h"

/**
 * push_f - Adds a new node at the beginning of a stack_t list.
 *
 * @head: Head of list.
 * @n: Number to be stored in node.
 * Return: Pointer to new node.
 */

void push_f(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (!stack)
		return;

	if (!code_line[1] || code_line[1][0] > '9' || code_line[1][0] < '0')
	{
		dprintf(STDOUT_FILENO, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (!new)
		return;

	new->n = atoi(code_line[1]);
	new->next = *stack;
	new->prev = NULL;

	if (new->next != NULL)
		new->next->prev = new;

	*stack = new;
}
