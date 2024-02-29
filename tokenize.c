#include "shell.h"
/**
 * tokenize - This function splits the command
 *
 * @cmd: pointer to the command input by the user
 *
 * Return: tokens
 *
 */
char **tokenize(char *cmd)
{
	int i = 0;
	int token_count = 0;
	char *delim = " ,'`\\*&#";
	char *token = strtok(cmd, delim);
	char **tokens = malloc(MAX_TOKENS * sizeof(char *));

	if (tokens == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	while (token != NULL && token_count < MAX_TOKENS - 1)
	{
		tokens[token_count] = strdup(token);

		if (tokens[token_count] == NULL)
		{
			perror("strdup");
			for (i = 0; i < token_count; i++)
			{
				free(tokens[i]);
			}
			free(tokens);
			exit(EXIT_FAILURE);
		}
		printf("%s\n", token);
		token = strtok(NULL, delim);
		token_count++;
	}
	tokens[token_count] = NULL;
	return (tokens);
}
/**
 * free_tokens - This function frees memory allocated to tokens
 *
 * @tokens: pointer to the tokens to be freed
 *
 */

void free_tokens(char **tokens)
{
	int i = 0;

	for (i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}
