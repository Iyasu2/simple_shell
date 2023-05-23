#include "main.h"

/**
 * _strcpy - copies a string
 * @source: source to copy from
 * @dest: destination to copy to
 *
 * Return: void
 */
void _strcpy(char *source, char *dest)
{
	int i = 0;

	for (; source[i] != '\0'; i++)
		dest[i] = source[i];
	dest[i] = '\0';
}

/**
 *_strcat - concatenates two strings
 *@destination: string to be concatenated to
 *@source:  string to concatenate
 *
 * Return: address of the new string
 */

char *_strcat(char *destination, char *source)
{
	char *new_string =  NULL;
	int len_dest = strlen(destination);
	int len_source = strlen(source);

	new_string = malloc(sizeof(*new_string) * (len_dest + len_source + 1));
	_strcpy(destination, new_string);
	_strcpy(source, new_string + len_dest);
	new_string[len_dest + len_source] = '\0';
	return (new_string);
}

/**
 *_strchr - locates a char in a string
 *@s: string to be searched
 *@c: char to be checked
 *
 *Return: pointer to the first occurence of c in s
 */

char *_strchr(char *s, char c)
{
	int i = 0;

	for (; s[i] != c && s[i] != '\0'; i++)
		;
	if (s[i] == c)
		return (s + i);
	else
		return (NULL);
}

/**
 * _getenv - gets the value of an environment variable
 * @name: name of the environment variable
 *
 * Return: the value of the variable as a string
 */
char *_getenv(char *name)
{
	char **my_environ;
	char *pair_ptr;
	char *name_cpy;

	for (my_environ = environ; *my_environ != NULL; my_environ++)
	{
		for (pair_ptr = *my_environ, name_cpy = name;
			*pair_ptr == *name_cpy; pair_ptr++, name_cpy++)
		{
			if (*pair_ptr == '=')
			break;
		}
		if ((*pair_ptr == '=') && (*name_cpy == '\0'))
			return (pair_ptr + 1);
	}
	return (NULL);
}

/**
 * _strtok - tokenizes a string
 * @string: string to be tokenized
 * @delim: delimiter to be used
 * @state_fun: pointer to be used to keep track of state of the function
 *
 * Return: The next available token
 */
char *_strtok(char *string, char *delim, char **state_fun)
{
	char *finish;

	if (string == NULL)
		string = *state_fun;

	if (*string == '\0')
	{
		*state_fun = string;
		return (NULL);
	}

	string += strspn(string, delim);
	if (*string == '\0')
	{
		*state_fun = string;
		return (NULL);
	}

	finish = string + strcspn(string, delim);
	if (*finish == '\0')
	{
		*state_fun = finish;
		return (string);
	}

	*finish = '\0';
	*state_fun = finish + 1;
	return (string);
}
