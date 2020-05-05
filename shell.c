/********************************************
 * @uther: Samuel Batali
 ********************************************
*           Custom Shell (C/C++)
*
*   Creating a basic command-line interpreter
*	  Process a limited number of built-in commands
*	  Perform error handling in various cases
*   Use fork() to run external and/or unix commands
*  
*******************************************/

#include <stdio.h>
#include <unistd.h>
#include <limits.h>

#include "/Users/dariokwo/Desktop/utilities/CUtilities.h"

int main(int argc, char const *argv[])
{
  // Functions provided in unistd lib
  // Get username of the user logged into the session
  // Get Absolute Path
  char *user = getlogin();
  char path[PATH_MAX];
  getcwd(path, PATH_MAX);

  // Use to check status of a child process
  int stat_loc;
  int wait = 1;

  // Tokenize path and count tokens
  int length = -1;
  char **split_path = split_string(path, '/');
  while (split_path[++length] != NULL)
    ;

  // Get current directory name
  char *curr_dir = split_path[length - 1];

  // Free unused space
  free(split_path);

  // Define buffer length when getting user inputs to avoid buffer overflow attack
  int buffer_length = 128;
  char buffer[buffer_length];
  printf("<%s> dir::%s:", user, curr_dir);
  while (fgets(buffer, buffer_length, stdin))
  {
    // command line keywords are separated by empty space
    char *trim_input = trim_string(buffer);
    if (!trim_input || strlen(trim_input) == 0)
      continue;
    if (!strcmp(trim_input, "quit") || !strcmp(trim_input, "exit"))
      break;

    // Tokenize buffer and count tokens
    length = -1;
    char **split_buffer = split_string(trim_string(buffer), ' ');
    while (split_buffer[++length] != NULL)
      ;

    // Execute built-in /customized commands for this shell
    // and execute others in using the unix CL-interpreter or terminal
    if (0)
    {
      // Execute custom commands here
    }
    else
    {
      // Create a child process to execute external and/or unix commands
      pid_t pid = fork();
      if (pid == 0)
      {
        // Child process created succesfully
        // execeute command
        int exec = execvp(split_buffer[0], split_buffer);
        if (exec < 0)
          // command not executed properly
          printf("Error: Execution failure or unknown command\n");

        exit(1);
      }
      else if (pid < 0)
        // Child proces not created
        printf("Error: Failed to create child process\n");
      else
      {
        // What should the parent process do? wait for child to finish or not
        if (wait)
          waitpid(pid, &stat_loc, WUNTRACED);
        else
          continue;
      }
    }

    free(split_buffer);
    printf("<%s> dir::%s:", user, curr_dir);
  }

  return 0;
}
