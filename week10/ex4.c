#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

#define SIZE 1000

int main() {
    DIR* currentDir = opendir("../week10/tmp/");
    if (currentDir == NULL) {
        printf("There is no such directory");
        return 0;
    }

    struct dirent* direntp;
    struct dirent* direnList[SIZE];

    int id = 0;
    while((direntp = readdir(currentDir)) != NULL) {
        direnList[id] = direntp;
        id++;
    }

    closedir(currentDir);

    printf("File - Hard Links\n");
    for (int i = 0; i < id; ++i) {
        int linksNumber = 0;

        for (int j = 0; j < id; ++j)
            if (direnList[i]->d_ino == direnList[j]->d_ino)
                linksNumber++;

        if (linksNumber >= 2) {
            printf("%s - ", direnList[i] -> d_name);

            for (int j = 0; j < id; ++j)
                if (direnList[i] -> d_ino == direnList[j] -> d_ino)
                    printf("%s ", direnList[j] -> d_name);
            printf("\n");
        }
    }

    return 0;
}
