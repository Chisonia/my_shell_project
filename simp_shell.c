#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
/**
 * main - This function creates a simple shell
 * Return: 0 on success
 */
int main(void)
{
	char *cmdptr = NULL;
	size_t len = 0;
	pid_t pid;
	int status;

	printf("$ ");
	while (getline(&cmdptr, &len, stdin) != EOF)
	{
		int str_count = strlen(cmdptr);

		cmdptr[str_count - 1] = '\0';
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			return (1);
		}
		else if (pid == 0)
		{
			printf("%s\n", cmdptr);
			char *argv[] = {cmdptr, NULL};

			execve(argv[0], argv, NULL);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
			printf("$ ");
		}
	}
	perror("getline");
	free(cmdptr);
	return (0);
}
