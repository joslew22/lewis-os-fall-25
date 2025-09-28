/* signal1.c - Modified to print additional message after handler */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Global variable to track if handler was invoked
volatile int signal_received = 0;

void handler(int signum)
{  // signal handler
    printf("Hello World!\n");
    signal_received = 1;  // Set flag instead of exiting
}

int main(int argc, char * argv[])
{
    signal(SIGALRM, handler);  // register handler to handle SIGALRM
    alarm(5);  // Schedule a SIGALRM for 5 seconds
    
    while(!signal_received);  // busy wait for signal to be delivered
    
    // After handler is invoked, print additional message
    printf("Turing was right!\n");
    
    return 0;
}