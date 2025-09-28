#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

// Global variables
volatile int signal_received = 0;
volatile int alarm_count = 0;
time_t start_time;

// SIGALRM handler - called every second
void alarm_handler(int signum) {
    printf("Hello World!\n");
    signal_received = 1;
    alarm_count++;
    
    // Reset alarm for another 1 second
    alarm(1);
}

// SIGINT handler - called when CTRL-C is pressed
void sigint_handler(int signum) {
    time_t end_time;
    time(&end_time);
    
    double elapsed = difftime(end_time, start_time);
    
    printf("\n\n=== Program Statistics ===\n");
    printf("Total alarms received: %d\n", alarm_count);
    printf("Total execution time: %.0f seconds\n", elapsed);
    
    exit(0);
}

int main() {
    // Record start time
    time(&start_time);
    
    // Register signal handlers
    signal(SIGALRM, alarm_handler);
    signal(SIGINT, sigint_handler);
    
    printf("Timer started. Press CTRL-C to stop and see statistics.\n");
    
    // Set initial alarm for 1 second
    alarm(1);
    
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