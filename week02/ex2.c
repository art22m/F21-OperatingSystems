#include <stdio.h>
#include <string.h>

int main() {
    char inputStr[256];
    
    printf("Input your sentence or word: \n");
    scanf("%[^'\n']s", inputStr);

    char reversedStr[256] = "";
    for (int i = strlen(inputStr) - 1, j = 0; i >= 0; --i, ++j) 
        reversedStr[j] = inputStr[i];

    printf("%s", reversedStr);
    return 0;
}