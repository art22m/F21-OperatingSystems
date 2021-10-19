#include <stdio.h>

typedef struct {
    unsigned int page;
    unsigned int age;
    unsigned int R;
} Frame;

void update_age(Frame frames[], int frames_number) {
    for(int i = 0; i < frames_number; ++i) {
        frames[i].age = frames[i].age >> 1;
        frames[i].age |= frames[i].R << 30;
        frames[i].R = 0;
    }
}

int index_least(Frame frames[], int frames_number) {
    int age = 99999, index = 0;

    for(int i = 0; i < frames_number; ++i)
        if (frames[i].age < age)
            age = frames[i].age, index = i;

    return index;
}

int find_page(int page, Frame frames[], int frames_number) {
    for (int i = 0; i < frames_number; ++i)
        if (frames[i].page == page)
            return i;

    return -1;
}

int main() {
    int hits_cnter = 0, misses_cnter = 0;

    int frames_number;
    printf("Enter frames number: ");
    scanf("%d", &frames_number);

    Frame frames[frames_number];
    for(int i = 0; i < frames_number; ++i) {
        frames[i].age = 0;
        frames[i].page = -1;
        frames[i].R = 0;
    }

    int clock_tick = 0;
    FILE *pageReferences = fopen("../input.txt", "r");
    while(!feof(pageReferences)) {
        int page;
        fscanf(pageReferences, "%d", &page);

        int page_id = find_page(page, frames, frames_number);
        if(page_id != -1) {
            hits_cnter++;
            frames[page_id].R = 1;
        } else {
            misses_cnter++;
            int replace_id = index_least(frames, frames_number);
            frames[replace_id].page = page;
            frames[replace_id].age = 1 << 30;
            frames[replace_id].R = 1;
        }

        if (clock_tick % 4 == 0)
            update_age(frames, frames_number);
        clock_tick++;
    }
    printf("Hit/Miss ratio is %d/%d\n", hits_cnter, misses_cnter);
    return 0;
}