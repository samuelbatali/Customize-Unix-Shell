#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *main_thread(void *commands)
{
    int sys = system((const char *)commands);
    if (sys == -1 || sys == 127)
        printf("Error: Execution of external command failed\n");

    pthread_exit(NULL);
}

void create_thread(char *commands)
{

    pthread_t mythread;
    // Create threads
    if (pthread_create(&mythread, NULL, main_thread, (void *)commands))
    {
        printf("*** Error creating thread ***\n");
        exit(-1);
    }

    // Bind to process
    if (pthread_join(mythread, NULL))
    {
        printf("*** Error joining thread ***\n");
        exit(-2);
    }
}