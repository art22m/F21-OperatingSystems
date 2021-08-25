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

void printPyramid(int n) {
    int numberOfStars[200];
    numberOfStars[0] = 1;
    for (int i = 1; i < n; ++i)
        numberOfStars[i] = numberOfStars[i - 1] + 2;

    for (int i = 0; i < n; ++i) {
        int numberOfTabs = (numberOfStars[n - 1] - numberOfStars[i]) / 2;

        for (int j = 0; j < numberOfTabs; ++j)
            printf(" ");

        for (int j = 0; j < numberOfStars[i]; ++j)
            printf("*");

        for (int j = 0; j < numberOfTabs; ++j)
            printf(" ");

        printf("\n");
    }
}

void printTriangle(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i + 1; ++j)
            printf("*");
        printf("\n");
    }
}

void printSquare(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            printf("*");
        printf("\n");
    }
}

void printReversePyramid(int n) {
    // The formula of the number of members of the arithmetic progression
    int numberOfStarsMaxRow = (n - 1) / 2 + 1;
    for (int i = 1; i <= numberOfStarsMaxRow; ++i) {
        for (int j = 0; j < i; ++j)
            printf("*");
        printf("\n");
    }

    for (int i = numberOfStarsMaxRow - 1; i >= 0; --i) {
        for (int j = 0; j < i; ++j)
            printf("*");
        printf("\n");
    }
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


    printf("Choose option: \n 1) Triangle\n 2) Pyramid\n 3) Reverse Pyramid\n 4) Square\n");

    int option = 0;
    scanf("%d", &option);

    switch (option) {
        case 1:
            printTriangle(n);
            break;
        case 2:
            printPyramid(n);
            break;
        case 3:
            printReversePyramid(n);
            break;
        case 4:
            printSquare(n);
            break;
        default:
            printf("The figure number is incorrect.");
    }

    return 0;
}