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
char **commands = NULL;
int status = 0;
char *line = NULL;
char *shell_name = NULL;
char **current_command = NULL;
int i, index, type_command = 0;
size_t len = 0;

signal(SIGINT, ctrl_c_handler);
shell_name = av[0];
while (1)
{
print("my_shell ", STDOUT_FILENO);
if (getline(&line, &len, stdin) == -1)
{
free(line);
exit(status);
}

/*remove newline*/
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
return (status);
}
