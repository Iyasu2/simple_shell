#include "main.h"
#include <stdlib.h>

/**
 * parse_input - shows type of the command
 * @command: command to be parsed
 *
 * Return: int representing the type of the command
 * Description -
 * EXTERNAL_COMMAND (1) represents commands like /bin/ls
 * INTERNAL_COMMAND (2) represents commands like exit, env
 * PATH_COMMAND (3) represents commands found in the PATH like ls
 * INVALID_COMMAND (-1) represents invalid commands
 */

int parse_input(char *command)
{
	int i;
	char *internal_command[] = {"env", "exit", NULL};

	for (i = 0; command[i] != '\0'; i++)
	{
		if (command[i] == '/')
		return (EXTERNAL_COMMAND);
	}
	for (i = 0; internal_command[i] != NULL; i++)
	{
		if (strcmp(command, internal_command[i]) == 0)
			return (INTERNAL_COMMAND);
	}
	return (INVALID_COMMAND);
}
