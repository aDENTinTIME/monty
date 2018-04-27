#include "monty.h"


/**
 * free_array - free tokens in array and the array itself
 *
 * @array: array of pointers to tokens
 */
void free_array(char **array)
{
	int i = 0;

	if (array == NULL)
		return;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}


/**
 * free_stack - Frees a stack_t list.
 *
 * @stack: Head of list.
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	temp = stack;

	if (!stack)
		return;
/*
 *	while (stack)
 *	{
 *		stack = temp->next;
 *		free(temp)
 *		temp = stack;
 *	}
 *	return;
 */
	while (1)
	{
		temp = stack->next;
		free(stack);
		if (!temp)
			return;
		stack = temp->next;
		free(temp);
		if (!stack)
			return;
	}
}
