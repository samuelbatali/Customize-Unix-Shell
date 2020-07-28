//
// Created by Samuel Batali
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "CFunctions.h"
// #include "CPPFunctions.hpp"

void print_cString_array(char **array)
{
    // Displaying C string array
    while (*array)
        printf("%s, ", *array++);
    printf("\n");
}

char *get_user()
{
    // return the name of the user logged into the system
    return getlogin();
}

// Split a string into tokens on the provided delimeter
// Store pointers to string tokens
// Remember to free space after use
char **split_string(char *str, char delimeter)
{
    char **tokens = (char **)malloc(strlen(str) * sizeof(char *));
    char *token = strtok(str, &delimeter);
    int index = 0;
    while (token != NULL)
    {
        tokens[index++] = token;
        token = strtok(NULL, &delimeter);
    }
    // terminate by NULL
    // Use this to check for tokens length
    tokens[index] = NULL;
    return tokens;
}

char *get_cdir()
{

    char path[PATH_MAX];
    getcwd(path, PATH_MAX);

    char *dir = (char *)malloc(strlen(path) + 1);
    strcpy(dir, path);

    return dir;

    // int length = -1;
    // char **split_path = split_string(path, '/');
    // while (split_path[++length] != NULL)
    // {
    //     printf("%s, ", split_path[length]);
    // }
    // printf("\n");

    // // Get current directory name
    // char *curr_dir = (char *)malloc(strlen(split_path[length - 1]) + 1);
    // strcpy(curr_dir, split_path[length - 1]);

    // printf("%s\n", curr_dir);

    // // Free unused space
    // free(split_path);

    // printf("%s\n", curr_dir);
    // return curr_dir;
}