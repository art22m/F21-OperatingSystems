#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
 * Initially, when we don't fork, the parent pid equal to zero.
 * When we fork for the first time, parent pid will change to child pid and
 * since child is a parent for himself, it will contain zero.
 */


int main() {
    pid_t pid = fork();

    for (int i = 1; i <= 10; ++i) {
        if (pid > 0)
            printf("Hello from parent [%d - %d]\n", pid, i);
        else if (pid == 0)
            printf("Hello from child [%d - %d]\n", pid, i);
        else
            return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}