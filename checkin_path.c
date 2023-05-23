/**
* checkin_path - checks if a command is found in the PATH variable
* @command: command to be used
*
* Return: path where the command is found in, NULL if not found
*/
char *checkin_path(char *command)
{
char **path_array = NULL;
char *with_command, *wt_command, *path_copy;
char *path = _getenv("PATH");
int i;

if (path == NULL || strlen(path) == 0)
return (NULL);
path_copy = malloc(sizeof(*path_copy) * (strlen(path) + 1));
_strcpy(path, path_copy);
path_array = parse_arguments(path_copy, ":");
for (i = 0;  path_array[i] != NULL;  i++)
{
wt_command = _strcat(path_array[i], "/");
with_command = _strcat(wt_command, command);
if (access(with_command, F_OK) == 0)
{
free(wt_command);
free(path_array);
free(path_copy);
return (with_command);
}
free(with_command);
free(wt_command);
}
free(path_copy);
free(path_array);
return (NULL);
}