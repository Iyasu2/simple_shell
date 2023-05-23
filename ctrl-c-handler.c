#include "main.h"

/**
 * ctrl_c_handler - handles the signal SIGINT
 * @signum: signal number
 *
 * Return: void
 */
void ctrl_c_handler(int signum)
{
	if (signum == SIGINT)
		print("\nmy_shell ", STDIN_FILENO);
}
