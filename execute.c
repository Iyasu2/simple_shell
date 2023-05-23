#include "main.h"

/**
* execute - executes a command
* @tokenized_command: tokenized form of the command
* @command_type: type of the command
*
* Return: void
*/
void execute(char **tokenized_command, int command_type)
{
void (*func)(char **command);

if (command_type == EXTERNAL_COMMAND)
{
if (execve(tokenized_command[0], tokenized_command, NULL) == -1)
{
perror(_getenv("PWD"));
exit(2);
}
}
if (command_type == PATH_COMMAND)
{
if (execve(checkin_path(tokenized_command[0]),
tokenized_command, NULL) == -1)
{
perror(_getenv("PWD"));
exit(2);
}
}
if (command_type == INTERNAL_COMMAND)
{
func = get_func(tokenized_command[0]);
func(tokenized_command);
}
if (command_type == INVALID_COMMAND)
{
print(shell_name, STDERR_FILENO);
print(": 1: ", STDERR_FILENO);
print(tokenized_command[0], STDERR_FILENO);
print(": not found\n", STDERR_FILENO);
status = 127;
}
}
