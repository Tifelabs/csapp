#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {                      
    printf("\t\t+++++ PROCESS ++++++\n\n");
    printf("NAME: [Main Process]  PID: %d\n", getpid());
    fflush(stdout);                             

    pid_t first_child = fork();

    if (first_child == -1) {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    } else if (first_child == 0) {
        printf("NAME: [First Child]  PID: %d\n", getpid());
        fflush(stdout);
        exit(0);
    } else {
        waitpid(first_child, NULL, 0);
        printf("NAME: [Parent]  PID: %d\n", getpid());
        fflush(stdout);
    }

    pid_t second_child = fork();

    if (second_child == -1) {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    } else if (second_child == 0) {
        printf("NAME: [Second Child]  PID: %d\n", getpid());

        FILE *fptr = fopen("event.txt", "w");
        if (fptr == NULL) {
            fprintf(stderr, "File error: could not open event.txt\n");
            exit(1);
        }

        fprintf(fptr, "Stracona Library\n");
        fclose(fptr);                          
        printf("NAME: [Second Child]  event.txt written\n");
        fflush(stdout);
        exit(0);                               
    } else {
        waitpid(second_child, NULL, 0);
        printf("NAME: [Parent]  PID: %d\n", getpid());
        fflush(stdout);
    }

    return 0;
}