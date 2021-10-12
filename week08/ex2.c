#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Each time we allocate 10 memory and do not free it,
 * as a result free memory is decreasing during runtime.
*/

int main() {
    int n = 2500000; // 10mb array of ints
    int *arr;

    for (int i = 0; i < 10; ++i) {
        arr = (int*) malloc(n * sizeof(int));
        memset(arr, 0, n * sizeof(int));
        printf("Memory was allocated %d time;\n", i + 1);
        sleep(1);
    }

    return 0;
}
