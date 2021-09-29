#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void* my_realloc(void *pointer, size_t size) {
//    printf("sizeof new array in bytes: %ld\n", size);
//    printf("size of 1st element %ld\n", sizeof(pointer[0]));
//    printf("new size: %ld\n", size / sizeof(pointer[0]));
    if (pointer == NULL) {
        return (void*)malloc(size);
    }

    if (size == 0) {
        free(pointer);
        return NULL;
    }

    void *new_array = (void*)malloc(size);
    memcpy(new_array, pointer, size);
    free(pointer);

    return new_array;
}

int main() {
    printf("Enter original array size: ");
    int n1 = 0;
    scanf("%d",&n1);

    int* arr = (int*)malloc(n1 * sizeof(int));
    for(int i = 0; i < n1; i++) {
        arr[i] = i;
        printf("%d ", arr[i]);
    }

    printf("\nEnter new array size: ");
    int n2 = 0;
    scanf("%d", &n2);

    arr = my_realloc(arr, n2 * sizeof(int));
    for (int i = 0; i < n2; ++i)
        printf("%d ", arr[i]);

    return 0;
}
