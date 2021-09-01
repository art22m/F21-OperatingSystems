#include <stdio.h>
#include <stdlib.h>

void swap(int *lhs, int *rhs) {
    int temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
}

void bubble_sort(int *arr, int arraySize) {
    for (int i = 0; i < arraySize - 1; ++i)
        for (int j = 0; j < arraySize - i - 1; ++j)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

int main() {
    int arraySize;
    printf("Input an array size: ");
    scanf("%d", &arraySize);

    printf("Input %d elements: ", arraySize);
    int *arr = (int*)malloc(arraySize * sizeof(int));

    // Input an array
    for (int i = 0; i < arraySize; ++i)
        scanf("%d", &arr[i]);

    bubble_sort(arr, arraySize); // call sort func

    printf("Your sorted array: ");
    for (int i = 0; i < arraySize; ++i)
        printf("%d ", arr[i]);
    return 0;
}