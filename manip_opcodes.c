#include "monty.h"


/**
 * push_f - Adds a new node at the beginning of a stack_t list.
 *
 * @stack: Head of stack.
 * @line_number: Line number for current line of code.
 */
void push_f(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int n;

	if (!stack)
		return;

	if (!code_line[1] || !strcmp(code_line[1], "") || only_nums(code_line[1]))
	{
		dprintf(STDOUT_FILENO, "L%d: usage: push integer\n", line_number);
		free(code_line[0]);
		code_line[0] = strdup("FATAL_PUSH_ERROR");
		return;
	}

	n = atoi(code_line[1]);

	new = malloc(sizeof(stack_t));
	if (!new)
		return;

	new->n = n;
	new->next = *stack;
	new->prev = NULL;

	if (new->next != NULL)
		new->next->prev = new;

	*stack = new;
}


/**
 * pall_f - Prints all the elements of a stack_t list.
 *
 * @stack: Head of stack.
 * @line_number: Line number for current line of code.
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


/**
 * pint_f - Prints the value at the top of the stack, followed by a new line.
 *
 * @stack: Head of stack.
 * @line_number: Line number for current line of code.
 */
void pint_f(stack_t **stack, unsigned int line_number)
{
	if (!stack)
		return;

	if (!*stack)
	{
		dprintf(STDOUT_FILENO, "L%d: can't pint, stack empty\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}


/**
 * pop_f - Deletes the first node of the stack.
 *
 * @stack: Head of stack.
 * @line_number: Line number for current line of code.
 */
void pop_f(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;

	if (!stack || !*stack)
	{
		dprintf(STDOUT_FILENO, "L%d: can\'t pop an empty stack\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if (temp->next != NULL)
	{
		temp->next->prev = NULL;
		*stack = temp->next;
	}
	else
		*stack = temp->next;
	free(temp);
}


/**
 * swap_f - Swaps the top two elements of the stack.
 *
 * @stack: Head of stack.
 * @line_number: Line number for current line of code.
 */
void swap_f(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	short_stack(stack, line_number);

	temp = *stack;

	temp->prev = temp->next;
	temp->next = temp->prev->next;
	temp->prev->prev = NULL;
	temp->prev->next = temp;

	*stack = temp->prev;
}
