#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#include "UnixProcess.h"

void process_unix_commands(char **commands, int wait)
{

    // Create a new process
    // Execute unix command

    int stat_loc;

    pid_t pid = fork();
    if (pid == 0)
    {
        // Child process created
        // Execute Unix command
        int exec = execvp(commands[0], commands);
        if (exec < 0)
        {
            // Failed to execute command
            printf("Error: Execution failure or unknown command\n");
        }
        exit(1);
    }
    else if (pid < 0)
    {
        // Child process is not created
        printf("Error: Failed to create child process\n");
    }
    else
    {
        // In the parent process right now
        // Either wait for child to finish, or continue
        if (wait != 0)
            waitpid(pid, &stat_loc, WUNTRACED);
    }
}