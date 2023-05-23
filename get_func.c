#include "main.h"

/**
* get_func - retrieves a function based on the command given and a mapping
* @command: string to check against the mapping
*
* Return: pointer to the proper function, or null on fail
*/
void (*get_func(char *command))(char **)
{
int i;
function_map mapping[] = {
{"env", env}, {"exit", quit}
};

for (i = 0;  i < 2;  i++)
{
if (strcmp(command, mapping[i].command_name) == 0)
return (mapping[i].func);
}
return (NULL);
}
