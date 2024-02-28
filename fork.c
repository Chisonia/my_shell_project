#include "shell.h"
/**
 * execute_command - executes command given by the user
 *
 * @cmd: command entered
 */
void execute_command(char *cmd)
{
	pid_t pid;
	int status;
	char *token, *argv[2];
	char full_path[MAX_PATH_LENGTH];
	char *path = getenv("PATH");

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (path == NULL)
		{
			fprintf(stderr, "PATH environment variable not found\n");
			exit(EXIT_FAILURE);
		}
		token = strtok(path, ":");
		while (token != NULL)
		{
			snprintf(full_path, sizeof(full_path), "%s/%s", token, cmd);
			argv[0] = full_path;
			argv[1] = NULL;
			if (access(full_path, X_OK) == 0)
			{
				execve(full_path, argv, NULL);
				perror("execve");
				exit(EXIT_FAILURE);
			}
			token = strtok(NULL, ":");
		}
		fprintf(stderr, "Command not found: %s\n", cmd);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}
}
