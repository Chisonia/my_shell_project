#include "shell.h"
/**
 * execute_command - executes command given by the user
 * @tokens: strings that has been tokenized
 */
void execute_command(char **tokens)
{
	pid_t pid;
	int status;
	char *path, full_path[MAX_PATH_LENGTH];
	char *path = getenv("PATH");

	if (path == NULL)
	{
		fprintf(stderr, "PATH environment variable not found\n");
		return;
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		int i;

		for (i = 0; tokens[i] != NULL; i++)
		{
			path_token = strtok(path, ":");
			while (path_token != NULL)
			{
				snprintf(full_path, sizeof(full_path), "%s/%s", path_token, tokens[i]);
				if (access(full_path, X_OK) == 0)
				{
					execve(full_path, tokens, NULL);
					perror("execve");
					exit(EXIT_FAILURE);
				}
				path_token = strtok(NULL, ":");
			}
			fprintf(stderr, "Command not found: %s\n", tokens[i]);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
}
