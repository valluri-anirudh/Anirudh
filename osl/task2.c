#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
void main() {
    int fd1, fd2, n = 1;
    char *buf;

    fd1 = open("f1", O_RDONLY);
    fd2 = open("f2", O_WRONLY);

    if (fd1 == -1 || fd2 == -1) {
        printf("\nerror");
    } else {
        while (n > 0) {
            n = read(fd1, &buf, 1);
            write(fd2, &buf, 1);
        }
    }
}
