#include <stdio.h>

void swapTwoNumbers(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int a = 0, b = 0;
    printf("Enter a 1st number: ");
    scanf("%d", &a);
    printf("Enter a 1st number: ");
    scanf("%d", &b);

    printf("Before swap: a = %d, b = %d\n", a, b);
    swapTwoNumbers(&a, &b);
    printf("After swap: a = %d, b = %d", a, b);

    return 0;
}