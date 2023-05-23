#include "main.h"

/**
* initializer - starts executing
* @current_command: try to check current token
* @type_command: parse token
*
* Return: void
*/

void initializer(char **current_command, int type_command)
{
pid_t pid;

if (type_command == EXTERNAL_COMMAND)
{
pid = fork();
if (pid == 0)
execute(current_command, type_command);
else
{
waitpid(pid, &status, 0);
status >>= 8;
}
}
else
execute(current_command, type_command);
}
