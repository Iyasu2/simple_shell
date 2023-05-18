#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_NUM_TOKENS 64

void parse_input(char *input, char **tokens) {
char *token;
int token_count = 0;

// Split the input into tokens based on whitespace
token = strtok(input, " \t\n");
while (token != NULL) {
tokens[token_count] = token;
token_count++;
token = strtok(NULL, " \t\n");
}

tokens[token_count] = NULL;  // Set the last token to NULL for execve
}

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
parse_input(line, args);

pid_t pid = fork();
if (pid == -1) {
perror("fork");
} else if (pid == 0) {
// Child process
execve(args[0], args, NULL);
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
