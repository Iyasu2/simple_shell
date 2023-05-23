#include "main.h"




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

signal(SIGINT, ctrl_c_handler);
shell_name = av[0];
while (1)
{
print("my_shell ", STDOUT_FILENO);
if (getline(&line, &len, stdin) == -1)
{
free(line);
}
type_command = parse_input(current_command[0]);
initializer(current_command, type_command);
}
free(line);
}
