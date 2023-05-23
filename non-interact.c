#include "main.h"
#include <string.h>

/**
 * non_interactive - handles non_interactive mode
 *
 * Return: void
 */

void non_interactive(void)
{
	char **current_command = NULL;
	int i, index, type_command = 0;
	size_t len = 0;

	if (isatty(STDIN_FILENO) == 0)
	{
		while (getline(&line, &len, stdin) != -1)
		{
			index = strcspn(line, "\n");
			line[index] = '\0';

			remove_comment(line);
			commands = parse_arguments(line, "; ");
			for (i = 0;  commands[i] != NULL;  i++)
			{
				current_command = parse_arguments(commands[i], " ");
				if (current_command[0] == NULL)
				{
					free(current_command);
					break;
				}
				type_command = parse_input(current_command[0]);
				initializer(current_command, type_command);
				free(current_command);
			}
			free(commands);
		}
		free(line);
		exit(status);
	}
}
