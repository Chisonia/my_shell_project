#include "shell.h"
/**
 * main - entry point
 *
 * Return: 0
 */
int main(void)
{
	char *cmd;
	char **tokens;

	while (1)
	{
		display_prompt();
		cmd = read_command();

		if (strcmp(cmd, "exit") == 0)
		{
			free(cmd);
			break;
		}
		tokens = tokenize(cmd);
		execute_command(tokens);
		free_tokens(tokens);
		free(cmd);
	}
	return (0);
}
