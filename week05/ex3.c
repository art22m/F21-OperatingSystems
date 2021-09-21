#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

#define BUFFER_SIZE 10
#define DELAY_BETWEEN_PRINTS 60

pthread_t consumerThread, producerThread;
int bufferPosition = 0,  buffer[10];

void* producerFunction(void* arg) {
    while (1) {
        while (BUFFER_SIZE <= bufferPosition)
            usleep(10);

        buffer[bufferPosition] = rand() % 10 + 1;
        bufferPosition += 1;
    }
}

void* consumerFunction(void* arg) {
    time_t last_print_time = 0;

    while (1) {
        while (bufferPosition <= 0)
            usleep(10);

        if (time(NULL) - last_print_time >= DELAY_BETWEEN_PRINTS) {
            printf("Number from buffer=%d\n", buffer[bufferPosition - 1]);
            last_print_time = time(NULL);
        }

        bufferPosition -= 1;
    }
}

int main() {
    pthread_create(&consumerThread, NULL, consumerFunction, NULL);
    pthread_create(&producerThread, NULL, producerFunction, NULL);

    pthread_join(consumerThread, NULL);
    pthread_join(producerThread, NULL);

    pthread_exit(0);
}