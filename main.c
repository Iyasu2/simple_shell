#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024

int main(void)
{
	char *line = NULL;
	char *args[MAX_INPUT_LENGTH];
	int status;
	size_t len = 0;

	while (1)
	{
		printf("#cisfun$ ");
		if ((getline(&line, &len, stdin) == -1))
		{
			continue;
		}
		if (strcmp(line, "^c") == 0)
		{
			free(line);
			return (0);
		}
		line[strcspn(line, "\n")] = 0;
		args[0] = line;
		args[1] = NULL;
		pid_t pid = fork();
		if (pid == -1)
		{
			perror("fork");
		}
		else if (pid == 0)
		{
			execve(args[0], args, NULL);
			perror("./shell");
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}
	if (line != NULL)
		free(line);

	return (0);
}
