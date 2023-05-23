#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <signal.h>


/*constants*/
#define EXTERNAL_COMMAND 1
#define INTERNAL_COMMAND 2
#define PATH_COMMAND 3
#define INVALID_COMMAND -1

#define min(x, y) (((x) < (y)) ? (x) : (y))

/**
*struct map - a struct that maps a command name to a function
*
*@command_name: name of the command
*@func: the function that executes the command
*/

typedef struct map
{
char *command_name;
void (*func)(char **command);
} function_map;

extern char **environ;
extern char *line;
extern char **commands;
extern char *shell_name;
extern int status;


void print(char *, int);
char **parse_arguments(char *, char *);
void ctrl_c_handler(int);
void remove_comment(char *);
int parse_input(char *);
void execute(char **, int);
char *checkin_path(char *);
void (*get_func(char *))(char **);
extern void non_interactive(void);
extern void initializer(char **current_command, int type_command);

#endif /*MAIN_H*/
