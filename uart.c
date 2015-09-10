#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define MAX_SIZE 1024

uint8_t write_to_uart (char * value, uint16_t length);

int main (int argc, char ** argv) {
    write_to_uart ("A", 1);
    return 0;
}

uint8_t
write_to_uart (char * value, uint16_t length) {
    char sysfs[MAX_SIZE];
    char uart_interface[32] = "/dev/ttyMFD1";
    int  fd = -1;

    fd = open (uart_interface, O_WRONLY);

    if (fd == -1) {
        printf ("Failed to open (%s) on write_to_uart.\n", sysfs);
        return 0x0;
    } else {
        if (write(fd, value, length * sizeof(char)) == -1) {
            printf("Failed to write to file descriptor.\n");
            close(fd);
            return 0x0;
        }
        close(fd);
    }

    return 0x1;
}