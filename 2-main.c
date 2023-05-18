#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "main.h"

#define MAX_INPUT_LENGTH 1024
#define MAX_NUM_TOKENS 64

int main(void) {
    char *line = NULL;
    char *args[MAX_NUM_TOKENS];
    int status;
    size_t len = 0;

    while (1) {
        printf("#cisfun$ ");
        if (getline(&line, &len, stdin) == -1) {
            continue;
        }

        if (strcmp(line, "^c") == 0) {
            free(line);
            return 0;
        }

        line[strcspn(line, "\n")] = '\0';

        // Parse the input into tokens
        parse_arguments(line, args);

        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
        } else if (pid == 0) {
            // Child process
            execve(args[0], args, NULL);
            perror("./shell");
            exit(1);
        } else {
            // Parent process
            waitpid(pid, &status, 0);
        }
    }

    if (line != NULL)
        free(line);

    return 0;
}
