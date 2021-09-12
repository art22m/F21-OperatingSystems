#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    printf("Murashko Artem Shell v1.0\n");
    printf("Input q or quit to exit\n");

    char *command;
    while(1) {
        scanf("%[^\n]", command);
        if (strcmp(command, "q") == 0 || strcmp(command, "quit") == 0)
            return 0;

        fflush(stdin); // clean buffer
        system(command);
    }
    return 0;
}
