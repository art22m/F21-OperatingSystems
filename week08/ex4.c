#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n = 2500000; // 10mb array of ints
    int *arr;
    struct rusage usage;

    for (int i = 0; i < 10; ++i) {
        printf("#%d allocation of memory\n", i + 1);
        getrusage(RUSAGE_SELF, &usage);
        // Print the maximum resident set size used (in kilobytes).
        printf("Maximum resident set size: %ld KB \n",usage.ru_maxrss);

        arr = (int*) malloc(n * sizeof(int));
        memset(arr, 0, n * sizeof(int));

        sleep(1);
    }

    return 0;
}