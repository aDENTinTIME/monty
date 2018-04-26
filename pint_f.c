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

	printf("%d\n", (*stack)->n);
}
