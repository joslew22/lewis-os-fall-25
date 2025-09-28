#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

// Global variable to track if handler was invoked
volatile int signal_received = 0;

// Signal handler function
void handler(int signum) {
    printf("Hello World!\n");
    signal_received = 1;
    
    // Reset alarm for another 5 seconds
    alarm(5);
}

int main() {
    // Register signal handler for SIGALRM
    signal(SIGALRM, handler);
    
    // Set initial alarm for 5 seconds
    alarm(5);
    
    // Infinite loop
    while(1) {
        // Wait for signal to be received
        if (signal_received) {
            printf("Turing was right!\n");
            signal_received = 0;  // Reset flag for next iteration
        }
    }
    
    return 0;
}