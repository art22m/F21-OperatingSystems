#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;

    int n = 3;
    while(n--) 
        pid = fork();
    sleep(5);	

    return EXIT_SUCCESS;
}