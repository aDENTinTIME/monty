#include "monty.h"


/**
 * pstr_f - Prints the string starting at the
 * top of the stack, followed by a new line.
 *
 * @stack: Head of stack.
 * @line_number: Line number for current line of code.
 */
void pstr_f(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	while (temp && temp->n && temp->n >= 0 && temp->n <= 127)
	{
		putchar(temp->n);
		temp = temp->next;
	}
	putchar('\n');
}


/**
 * rotl_f - Rotates the stack to the top.
 *
 * @stack: Head of stack.
 * @line_number: Line number for current line of code.
 */
void rotl_f(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	if (!stack)
		return;

	temp = *stack;

	if (!temp)
		return;

	while (temp->next)
	{
		temp = temp->next;
	}

	temp->next = *stack;
	temp->next->prev = temp;

	temp = temp->next->next;

	*stack = temp;
	temp->prev->next = NULL;
	temp->prev = NULL;
}


/**
 * rotr_f - Rotates the stack to the bottom.
 *
 * @stack: Head of stack.
 * @line_number: Line number for current line of code.
 */
void rotr_f(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	if (!stack)
		return;

	temp = *stack;

	if (!temp)
		return;

	while (temp->next)
	{
		temp = temp->next;
	}

	temp->next = *stack;
	temp->next->prev = temp;

	*stack = temp;
	temp->prev->next = NULL;
	temp->prev = NULL;
}
