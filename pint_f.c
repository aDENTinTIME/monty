#include "monty.h"

/**
 * pint_f - Prints all the elements of a stack_t list.
 *
 * @h: Head of list.
 * Return: Number of nodes.
 */

void pint_f(stack_t **stack, unsigned int line_number)
{
	if (!stack)
		return;

	if (!*stack)
	{
		dprintf(STDOUT_FILENO, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
