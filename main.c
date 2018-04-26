#include "monty.h"

/*
create global variable, maybe in header file
I'm thinking it'll probably store the head of the list/stack?
maybe line number?
*/

/*
void cleanup(FILE *fp, char *path, char *line, char **array)
{
	if (fp)
		fclose(fp);
	if (path)
		free(path);
	if (line)
		free(line);
	if (array)
		free_array(array);
}
*/


void (*find_opcode(char *array, unsigned int line_number))(stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t instruct[] = {
		{"push", push_f},
/*		{"push", push_f},
		be ready to use push_f2
*/		{"pall", pall_f},
		{"pint", pint_f},
		{"nop", NULL},
		{NULL, NULL}
	};

	i = 0;
	code_line = tokenizer(array, " ");
	while (instruct[i].opcode)
	{
		if (!strcmp(instruct[i].opcode, code_line[0]))
			return (instruct[i].f);
		i++;
	}
	dprintf(STDOUT_FILENO, "L%d: unknown instruction %s\n", line_number, code_line[0]);
	free_array(code_line);
	exit(EXIT_FAILURE);
}

void parse(char *path, int *error)
{
	FILE *fp = NULL;
	size_t count = 0;
	char *line = NULL, **array = NULL;
	void (*func)(stack_t **stack, unsigned int line_number);
	stack_t *stack = NULL;
	unsigned int line_number = 1;

	if (*error)
		return;

	fp = fopen(path, "r");
	while (1)
	{
		if ((getline(&line, &count, fp)) == -1)
		{
			fclose(fp);
			free(path);
			return;
/* maybe exit success? or return idk
   do i need a special exit message?
*/		}
		if (line)
		{
			array = tokenizer(line, "\n");
			free(line);
			line = NULL;
		}
		func = find_opcode(array[0], line_number);
		if (func)
			func(&stack, line_number);
		free_array(code_line);
		code_line = NULL;
		free_array(array);
		line_number++;
	}
}

void make_path(char **path, char *filename, int *error)
{
	if (*error)
		return;

	*path = malloc(strlen(filename) + 3);
	if (!*path)
	{
		dprintf(STDOUT_FILENO, "Error: malloc failed\n");
		*error = 1;
		return;
	}
	strcpy(*path, "./");
	strcat(*path, filename);
}

char **code_line = NULL;

int main(int argc, char **argv)
{
	int error;
	char *path, *filename;

	error = 0;
	path = NULL;
	filename = NULL;

	correct_number_of_arguments(argc, &error);
	filename = argv[1];
	make_path(&path, filename, &error);
	can_access_file(path, filename, &error);
	parse(path, &error);
/*
  read(fp, buff, count);
  should i use fopen or just open??

  get args
  prepend path to file
  open file
  read file
  perform functions on each line of file
  check for EOF
  exit with success code
  or error code if necessary

  exit or return

  cleanup();
*/
	if (error)
		exit(EXIT_FAILURE);

	exit(EXIT_SUCCESS);

}
