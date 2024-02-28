#include "shell.h"
int main(void)
{
	char *cmd;

	while (1)
	{
		display_prompt();
		cmd = read_command();
		if (strcmp(cmd, "exit") == 0)
		{
			free(cmd);
			break;
		}
		execute_command(cmd);
		free(cmd);
	}
	return (0);
}
