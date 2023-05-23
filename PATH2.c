#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int findin_path(char *command)
{
	char *path = getenv("PATH");
	char *directory;
	char *token;
	struct stat file_info;
	int found = 0;

	if (path == NULL)
		return (1);

	token = strtok(path, ":");

	while (token != NULL)
	{
		directory = malloc(strlen(token) + strlen(command) + 2);
		if (directory == NULL)
			return (1);
		strcpy(directory, token);
		strcat(directory, "/");
		strcat(directory, command);

		if (stat(directory, &file_info) == 0)
		{
			command = directory;
			return (0);
		}

		free(directory);
		token = strtok(NULL, ":");
	}

	return (1);
}
