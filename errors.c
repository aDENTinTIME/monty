#include "monty.h"

void correct_number_of_arguments(int argc, int *error)
{
	if (*error)
		return;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		*error = 1;
		return;
	}
}

void can_access_file(char *path, char *filename, int *error)
{
	if (*error)
		return;

	if (access(path, F_OK) || access(path, R_OK) || !access(path, X_OK))
	{
		dprintf(STDOUT_FILENO, "Error: Can\'t open file %s\n", filename);
		free(path);
		*error = 1;
		return;
	}
}

