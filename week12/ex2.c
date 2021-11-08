#include <stdlib.h>
#include <stdio.h>
#include <linux/input.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

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

    while (1) {
        read(fd, &event, sizeof event);
        if (event.type == EV_KEY && event.value <= 2 && event.value >= 0)
            printf("\n%s 0x%04x (%d)\n", event_values[event.value], (int)event.code, (int)event.code);
    }

    fflush(stdout);
    fprintf(stderr, "%s.\n", strerror(errno));
    return EXIT_FAILURE;
}