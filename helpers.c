#include "monty.h"


/**
 * find_opcode - Checks if opcode exists.
 *
 * @array: String containing entire unparsed line of code.
 * @line_number: Line number for current line of code.
 * @stack: Head of stack.
 * Return: Pointer to function or NULL if nonexistent.
 */
void (*find_opcode(char **array, unsigned int line_number, stack_t **stack))\
		(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t instruct[] = {
		{"push", push_f},
		{"pall", pall_f},
		{"pint", pint_f},
		{"pop", pop_f},
		{"swap", swap_f},
		{"add", math},
		{"sub", math},
		{"div", math},
		{"mul", math},
		{"mod", math},
		{"pchar", pchar_f},
		{"nop", NULL},
		{NULL, NULL}
	};

	if (!array)
		return (NULL);

	code_line = tokenizer(array[0], " ");

	if (!code_line || code_line[0][0] == '#')
		return (NULL);

	while (instruct[i].opcode)
	{
		if (!strcmp(instruct[i].opcode, code_line[0]))
		{
			return (instruct[i].f);
		}
		i++;
	}
	dprintf(STDOUT_FILENO, "L%d: unknown instruction %s\n",
		line_number, code_line[0]);
	free_array(code_line);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}


/**
 * parse - Parses input file and executes bytecode.
 *
 * @path: Path to file.
 */
void parse(char *path)
{
	FILE *fp = NULL;
	size_t count = 0;
	char *line = NULL, **array = NULL;
	void (*func)(stack_t **stack, unsigned int line_number);
	stack_t *stack = NULL;
	unsigned int line_number = 1;

	fp = fopen(path, "r");
	if (!fp)
		viable_file(path, "");
	free(path);
	while (1)
	{
		if ((getline(&line, &count, fp)) == -1)
		{
			fclose(fp);
			free_stack(stack);
			free(line);
			return;
		}
		if (line)
		{
			array = tokenizer(line, "\n");
			free(line);
			line = NULL;
		}
		if (array)
		{
			func = find_opcode(array, line_number, &stack);
			if (func)
				func(&stack, line_number);
			free_array(code_line);
			code_line = NULL;
			free_array(array);
			array = NULL;
		}
		line_number++;
	}
}


/**
 * correct_number_of_arguments - Checks if the correct
 * number of arguments have been passed to the program.
 *
 * @argc: Argument count.
 */
void correct_number_of_arguments(int argc)
{
	if (argc != 2)
	{
		dprintf(STDOUT_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}


/**
 * viable_file - Checks file's viability.
 *
 * @path: Path to file.
 * @filename: Name of file.
 */
void viable_file(char *path, char *filename)
{
	if (access(path, F_OK) || access(path, R_OK) || !access(path, X_OK))
	{
		dprintf(STDOUT_FILENO, "Error: Can\'t open file %s\n", filename);
		free(path);
		exit(EXIT_FAILURE);
	}
}


/**
 * make_path - Creates the path to a file in the current directory.
 *
 * @path: Variable to hold complete path.
 * @filename: Name of file to append to the path.
 */
void make_path(char **path, char *filename)
{
	*path = malloc(strlen(filename) + 3);
	if (!*path)
	{
		dprintf(STDOUT_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	strcpy(*path, "./");
	strcat(*path, filename);
}
