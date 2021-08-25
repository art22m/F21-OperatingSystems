#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int intVar = INT_MAX;
    float floatVar = FLT_MAX;
    double doubleVar = DBL_MAX;

    printf("Size of Int = %lu, Max value of Int = %d\n", sizeof(intVar), intVar);
    printf("Size of Float = %lu, Max value of Float = %e\n", sizeof(floatVar), floatVar);
    printf("Size of Double = %lu, Max value of Double = %e\n", sizeof(doubleVar), doubleVar);

    return 0;
}