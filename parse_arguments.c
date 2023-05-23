#include "main.h"

/**
 * parse_arguments - parses input into tokens
 * @input_string: input to be parsed
 * @delim: delimiter to be used
 *
 * Return: array of tokens
 */

char **parse_arguments(char *input_string, char *delim)
{
	int token_count = 0;
	char **av = NULL;
	char *token = NULL;
	char *state_fun = NULL;

	token = _strtok(input_string, delim, &state_fun);

	while (token != NULL)
	{
		av = _realloc(av, sizeof(*av) * token_count,
				sizeof(*av) * (token_count + 1));
		av[token_count] = token;
		token = _strtok(NULL, delim, &state_fun);
		token_count++;
	}

	av = _realloc(av, sizeof(*av) * token_count, sizeof(*av) * (token_count + 1));
	av[token_count] = NULL;

	return (av);
}
