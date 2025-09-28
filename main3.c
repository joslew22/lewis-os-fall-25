#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     // Added for fork(), getpid(), getppid(), sleep()
#include <sys/wait.h>   // Added for wait()

void child_process();

// parent process
int main() {
    int pid;
    int i;
    
    for (i = 0; i < 2; i++) {
        pid = fork(); // stores two child pids
        
        if (pid == 0)
            child_process();
        else if (pid < 0)
            exit(1);
    }
    
    for (i = 0; i < 2; i++) {
        int status;
        int completed_pid = wait(&status);
        printf("Child Pid: %d has completed\n", completed_pid);
    }
    
    return 0;
}

// run one child process
void child_process() {
    int pid = getpid();
    int parent_pid = getppid();
    
    srandom(pid % 42); // seeding random number
    int n = 1 + (random() % 30); // random number no more than 30
    int i;
    
    for (i = 0; i < n; i++) {  // FIXED: Changed from i < 2 to i < n
        int time = 1 + (random() % 10); // sleep time no more than 10 seconds
        printf("Child Pid: %d is going to sleep!\n", pid);
        sleep(time); // sleep
        printf("Child Pid: %d is awake!\nWhere is my Parent: %d?\n", pid, parent_pid); // print if awake
    }
    
    exit(0);
}

