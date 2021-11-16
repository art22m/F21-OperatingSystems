#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLUMNS 3

void printR(int index, int** r) {
    printf("R = {");
    for (int j = 0; j < COLUMNS - 1; j++)
        printf("%d, ", r[index][j]);
    printf("%d}, process -> %d\n", r[index][COLUMNS - 1], index + 1);
}

void printA1(int* a) {
    printf("A1 = {");
    for (int j = 0; j < COLUMNS - 1; j++)
        printf("%d, ", a[j]);
    printf("%d}\n", a[COLUMNS - 1]);
}

void printAl(int index, int* a, int** c) {
    printf("Al = {");
    for (int j = 0; j < COLUMNS - 1; j++) {
        printf("%d, ", c[index][j]);
        a[j] += c[index][j];
    }
    printf("%d}\n", c[index][COLUMNS - 1]);
    a[COLUMNS - 1] += c[index][COLUMNS - 1];
}

void printA2(int* a) {
    printf("A2 = {");
    for (int j = 0; j < COLUMNS - 1; j++)
        printf("%d, ", a[j]);
    printf("%d}\n\n", a[COLUMNS - 1]);
}

int main() {
    FILE *file;
//    file = fopen("../input_dl.txt", "r"); // file with deadlock
    file = fopen("../input_ok.txt", "r"); // file without deadlock

    if (file == NULL){
        printf("Cannot open the file\n");
        return 0;
    }

    int* e = (int*)malloc(COLUMNS * sizeof(int));
    int* a = (int*)malloc(COLUMNS * sizeof(int));
    int** c = (int**)malloc(ROWS * sizeof(int*));
    int** r = (int**)malloc(ROWS * sizeof(int*));

    for (int i = 0; i < ROWS; ++i) {
        *(c + i) = (int *) malloc(COLUMNS * sizeof(int));
        *(r + i) = (int *) malloc(COLUMNS * sizeof(int));
    }

    for (int i = 0; i < COLUMNS; ++i)
        fscanf(file, "%d", &e[i]);

    for (int i = 0; i < COLUMNS; ++i)
        fscanf(file, "%d", &a[i]);

    for (int i = 0; i < ROWS; ++i)
        for (int j = 0; j < COLUMNS; ++j)
            fscanf(file, "%d", &c[i][j]);

    for (int i = 0; i < ROWS; ++i)
        for (int j = 0; j < COLUMNS; ++j)
            fscanf(file, "%d", &r[i][j]);

    int* r_list = (int*)malloc(ROWS * sizeof(int));
    for (int i = 0; i < ROWS; i++)
        *(r_list + i) = 1;

    int isDeadlockFound = 0, isChecked = 1;

    int times = ROWS;
    while (times--) {
        isDeadlockFound = 1;

        for (int i = 0; i < ROWS; i++) {
            if (r_list[i] == 1) {
                isChecked = 1;
                for (int j = 0; j < COLUMNS; j++)
                    isChecked = a[j] >= r[i][j] ? isChecked * 1 : isChecked * 0;

                if (isChecked) {
                    isDeadlockFound = 0, r_list[i] = 0;

                    printR(i, r);
                    printA1(a);
                    printAl(i, a, c);
                    printA2(a);

                    break;
                }
            }
        }

        if (isDeadlockFound) {
            printf("Deadlock found =(\n");
            break;
        }
    }

    if (isDeadlockFound == 0)
        printf("Deadlock was not found =)\n");

    fclose(file);
    return 0;
}