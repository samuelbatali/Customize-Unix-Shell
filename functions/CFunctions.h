//
// Created by Samuel Batali
//

#ifndef CFunctions_h
#define CFunctions_h

// Splits a string into words tokens
char **split_string(char *str, char delimeter);

// Get name of logined user
char *get_user();

// Get the current working directory
char *get_cdir();

// Dispay char**
void print_cString_array(char **array);

#endif