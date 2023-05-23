#include "main.h"
#include <stdio.h>

/**
 * main - the main shell code
 * @ac: number of arguments passed
 * @av: program arguments to be parsed
 *
 * prints prompt and takes input
 * serve as the main code for the project
 * Return: 0 on success
 */
int main(int ac __attribute__((unused)), char **av)
{
	char *line = NULL;
	char *shell_name = NULL;
	size_t len = 0;

	shell_name = av[0];
	while (1)
	{
		printf("my_shell ");
		if (getline(&line, &len, stdin) == -1)
		{
			free(line);
		}
	}
}
