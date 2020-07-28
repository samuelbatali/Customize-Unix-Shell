/***************************************
 * @auther: Samuel Batali
 * Utility functions for C programs
***************************************/
#include <stdlib.h>
#include <string.h>

// Remove whitespace at the beginning of a string
char *ltrim(char *str)
{
    // Check for null case
    if (strncmp(str, "", 1) == 0)
        return str;

    while (*str == ' ' || *str == '\n' || *str == '\t')
        str++;
    return str;
}

// Removes whitespace, new_line and tabs at the end of a string
char *rtrim(char *str)
{
    // Check for null case
    if (strncmp(str, "", 1) == 0)
        return str;

    // remove tabs or newline
    size_t length = strlen(str);

    // remove whitespace
    char *end = str + length;
    while (*--end == ' ' || *end == '\n' || *end == '\t')
        *(end) = '\0';
    return str;
}

// Trim a string by calling ltrim and rtrim above
char *trim_string(char *str)
{
    return rtrim(ltrim(str));
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
