//
// Created by Samuel Batali
//

#ifndef MainThread_h
#define MainThread_h

// Create and bind thread to execute the given command
void create_thread(char **command);

void *main_thread(void *command);

#endif