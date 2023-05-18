#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "main.h"

#define MAX_INPUT_LENGTH 1024
#define MAX_NUM_TOKENS 64
extern char** environ;

int main(void) {
    char *line = NULL;
    char *args[MAX_INPUT_LENGTH];
    int status;
    size_t len = 0;
	pid_t pid;

    while (1) {
        printf("#cisfun$ ");
        if ((getline(&line, &len, stdin) == -1)) {
            if (feof(stdin))
				exit(EXIT_SUCCESS);
            continue;
        }

        if (strcmp(line, "^c") == 0) {
            free(line);
            return 0;
        }

        line[strcspn(line, "\n")] = 0;

        // Parse the input into tokens
        parse_arguments(line, args);
        args[0] = line;
		args[1] = NULL;
		pid = fork();
        if (pid == -1) {
            perror("fork");
            }
             else if (pid == 0) {
            // Child process
            execve(args[0], args, environ);
            perror("./shell");
        } else {
            // Parent process
            waitpid(pid, &status, 0);
        }
    }

    if (line != NULL)
        free(line);

    return 0;
}
