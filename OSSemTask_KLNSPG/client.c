#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>

int main()
{
    int fd;
    bool exitter = false;
    char input[128];

    char *me = "/tmp/KLNSPG";

    fd = open(me, O_WRONLY);
    wait(NULL);
    printf("Write here texts whiches wanted to be seen in the pipeline.\nAfter entering 'exit' you will leave this mode.\n");
    while (!exitter)
    {
        scanf("%s", input);
        if (strcmp(input, "exit") == 0)
        {
            exitter = true;
            close(fd);
            exit(0);
        }
        else
        {
            printf("Entered text: %s\n", input);
            write(fd, input, (strlen(input) + 1));
        }
    }
    return 0;
}
