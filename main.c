#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
int pipefd[2];
pid_t pid;

// Create a pipe
if (pipe(pipefd) == -1) {
perror("pipe");
exit(EXIT_FAILURE);
}

// Fork a child process
pid = fork();

if (pid == -1) {
perror("fork");
exit(EXIT_FAILURE);
} else if (pid == 0) {
// Child process
// Close the read end of the pipe
close(pipefd[1]);

// Duplicate the read end of the pipe to stdin
if (dup2(pipefd[0], STDIN_FILENO) == -1) {
perror("dup2");
exit(EXIT_FAILURE);
}

// Execute the "ls" command
execlp("/bin/ls", "ls", NULL);

// If execlp() returns, an error occurred
perror("execlp");
exit(EXIT_FAILURE);
} else {
// Parent process
// Close the write end of the pipe
close(pipefd[0]);

// Read the command from stdin
char command[256];
fgets(command, sizeof(command), stdin);

// Write the command to the pipe
write(pipefd[1], command, sizeof(command));

// Close the write end of the pipe
close(pipefd[1]);

// Wait for the child process to finish
wait(NULL);
}

return 0;
}
