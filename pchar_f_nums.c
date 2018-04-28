#include "monty.h"


/**
 * only_nums - Checks if string contains anything other than a number.
 *
 * @s: String.
 * Return: 0 if string is only numbers, 1 otherwise.
 */
int only_nums(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] > '9' || s[i] < '0')
			if (s[i] != '-')
				return (1);
		i++;
	}
	return (0);
}


/**
 * pchar_f - Prints the char at the top of the stack, followed by a new line.
 *
 * @stack: Head of stack.
 * @line_number: Line number for current line of code.
 */
void pchar_f(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		dprintf(STDOUT_FILENO, "L%d: can\'t pchar, stack empty\n",
			 line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		dprintf(STDOUT_FILENO, "L%d: can\'t pchar, value out of range\n",
			 line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}
