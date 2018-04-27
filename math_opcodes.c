#include "monty.h"


/**
 * stack_length - Counts and returns the number of nodes.
 *
 * @stack: Head of stack.
 * Return: Number of nodes.
 */
size_t stack_length(stack_t **stack)
{
	stack_t *step;
	size_t count;

	if (!stack || !*stack)
		return (0);

	step = *stack;
	count = 0;

	while (step)
	{
		step = step->next;
		count++;
	}
	return (count);
}


/**
 * short_stack - Checks if stack is to short to perform biline operations
 *
 * @stack: Head of stack.
 * @line_number: Line number for current line of code.
 */
void short_stack(stack_t **stack, unsigned int line_number)
{
	if (stack_length(stack) < 2)
	{
		if (!strcmp("add", code_line[0]))
			dprintf(STDOUT_FILENO, "L%d: can\'t add, stack too short\n", line_number);
		else if (!strcmp("sub", code_line[0]))
			dprintf(STDOUT_FILENO, "L%d: can\'t sub, stack too short\n", line_number);
		else if (!strcmp("mul", code_line[0]))
			dprintf(STDOUT_FILENO, "L%d: can\'t mul, stack too short\n", line_number);
		else if (!strcmp("div", code_line[0]))
			dprintf(STDOUT_FILENO, "L%d: can\'t div, stack too short\n", line_number);
		else if (!strcmp("mod", code_line[0]))
			dprintf(STDOUT_FILENO, "L%d: can\'t mod, stack too short\n", line_number);
		else /* swap */
			dprintf(STDOUT_FILENO, "L%d: can\'t swap, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}


/**
 * math - Does math.
 *
 * @stack: Head of stack.
 * @line_number: Line number for current line of code.
 */
void math(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	short_stack(stack, line_number);

	temp = *stack;
	*stack = temp->next;

	if (!strcmp("add", code_line[0]))
		temp->next->n += temp->n;
	else if (!strcmp("sub", code_line[0]))
		temp->next->n -= temp->n;
	else if (!strcmp("mul", code_line[0]))
		temp->next->n *= temp->n;
	else if (!temp->n)
	{
		dprintf(STDOUT_FILENO, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if (!strcmp("div", code_line[0]))
		temp->next->n /= temp->n;
	else /* mod */
		temp->next->n %= temp->n;

	temp->next->prev = NULL;

	free(temp);
}
