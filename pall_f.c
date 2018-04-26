#include "monty.h"

/**
 * pall_f - Prints all the elements of a stack_t list.
 *
 * @h: Head of list.
 * Return: Number of nodes.
 */

void pall_f(stack_t **stack, unsigned int line_number)
{
	stack_t *step;

	(void)line_number;

	if (!stack)
		return;

	step = *stack;
	while (step)
	{
		printf("%d\n", step->n);
		step = step->next;
	}
}
