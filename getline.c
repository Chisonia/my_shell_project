#include "shell.h"
/**
 * read_command - reads command given by the user
 *
 * Return: input
 */
char *read_command()
{
	char *input = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&input, &len, stdin);
	if (read == EOF)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}
	if (input[read - 1] == '\n')
	{
		input[read - 1] = '\0';
	}
	return (input);
}
