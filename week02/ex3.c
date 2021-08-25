#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

bool isNumber(char number[]) {
    if (number[0] == '-') {
        printf("You entered a negative number");
        return false;
    }

    for (int i = 0; i < number[i]; ++i)
        if (!isdigit(number[i])) {
            printf("You entered not a number");
            return false;
        }

    return true;
}

int main(int argc, char *argv[]) {
    // Check if arguments were passed
    if (argc < 2) {
        printf("No arguments were passed");
        return 0;
    }

    // Check if number
    if (!isNumber(argv[1]))
        return 0;

    int n;
    sscanf(argv[1], "%d", &n);

    // Calculate the number of stars in every row
    int numberOfStars[256];
    numberOfStars[0] = 1;
    for (int i = 1; i < n; ++i)
        numberOfStars[i] = numberOfStars[i - 1] + 2;

    for (int i = 0; i < n; ++i) {
        // Calculate the number of spaces needed to build correct pyramid
        int numberOfTabs = (numberOfStars[n - 1] - numberOfStars[i]) / 2;

        for (int j = 0; j < numberOfTabs; ++j)
            printf(" ");

        for (int j = 0; j < numberOfStars[i]; ++j)
            printf("*");

        for (int j = 0; j < numberOfTabs; ++j)
            printf(" ");

        printf("\n");
    }

    return 0;
}