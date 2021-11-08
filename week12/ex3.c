#include <stdlib.h>
#include <stdio.h>
#include <linux/input.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 6

static const char *const event_values[3] =
{
        "RELEASED",
        "PRESSED",
        "REPEATED"
};

int main() {
    const char* dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    struct input_event event;
    int fd = open(dev, O_RDONLY);

    if (fd == -1) {
        fprintf(stderr, "Cannot open %s: %s.\n", dev, strerror(errno));
    }

    int buffer[BUFFER_SIZE];
    while (1) {
        read(fd, &event, sizeof event);
        if (event.type == EV_KEY && event.value == 1) {
            for (int i = BUFFER_SIZE - 1; i >= 1; --i)
                buffer[i] = buffer[i - 1];
            buffer[0] = event.code;

            if (buffer[0] == KEY_E && buffer[1] == KEY_P)
                printf("I passed the Exam!\n");
            else if (buffer[0] == KEY_P && buffer[1] == KEY_A && buffer[2] == KEY_C)
                printf("Get some cappuccino!\n");
            else if (buffer[0] == KEY_A && buffer[1] == KEY_N)
                printf("My name is Artem!\n");
        }
    }

    fflush(stdout);
    fprintf(stderr, "%s.\n", strerror(errno));
    return EXIT_FAILURE;
}