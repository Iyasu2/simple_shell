#include "main.h"
#include <stdio.h>
#include <string.h>
extern char** environ;

void parse_arguments(char *input, char **tokens) {
    char *token;
    int token_count = 0;

    // Split the input into tokens based on whitespace
    token = strtok(input, " \t\n");
    while (token != NULL && token_count < MAX_NUM_TOKENS - 1) {
        tokens[token_count] = token;
        token_count++;
        token = strtok(NULL, " \t\n");
    }

    tokens[token_count] = NULL;  // Set the last token to NULL for execve
}
