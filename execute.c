/**
* execute - executes a command
* @tokenized_command: tokenized form of the command
* @command_type: type of the command
*
* Return: void
*/
void execute(char **tokenized_command, int command_type)
{

if (command_type == EXTERNAL_COMMAND)
{
if (execve(tokenized_command[0], tokenized_command, NULL) == -1)
{
perror(getenv("PWD"));
exit(2);
}
}
if (command_type == PATH_COMMAND)
{
if (execve(checkin_path(tokenized_command[0]),
tokenized_command, NULL) == -1)
{
perror(getenv("PWD"));
exit(2);
}
}
}
