#include <stdio.h>
#include <pthread.h>

const int N = 5;

void *threadFunc(int *id) {
    printf("Thread %d prints message\n", *id);
    return NULL;
}

int main() {
    pthread_t threads[N];

    for (int i = 0; i < N; ++i) {
        printf("Create thread %d\n", i);
        pthread_create(&threads[i], NULL, threadFunc, &i);
        pthread_join(threads[i], NULL); // If you comment this line, the output will be asynchronous, otherwise it is synchronous
        printf("Exit thread %d\n", i);
    }
    return 0;
}