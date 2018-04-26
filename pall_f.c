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

	if (!stack)
		return;

	if (!*stack)
	{
		dprintf(STDOUT_FILENO, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	step = *stack;
	while (step)
	{
		printf("%d\n", step->n);
		step = step->next;
	}
}
