#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    int child;

    mkfifo("Martinak Matyas", S_IRUSR | S-IWUSR);
    child = fork();

    if(child > 0) {
        char s[1024];
        int fd;

        fd = open("Martinak Matyas", O_RDONLY);
        read(fd, s, sizeof(s));
        printf("%s", s);
        close(fd);
        unlink("Martinak Matyas");

    } else if(child == 0) {
        int fd = open("Martinak Matyas", O_RDONLY);
        write(fd, "MM KLNSPG\n", 12);
        close(fd);

    }
    return 0;
}