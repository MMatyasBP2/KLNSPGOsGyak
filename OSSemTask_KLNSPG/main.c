#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>

void InterruptHandler(int sig);

char *KLNSPG = "/tmp/KLNSPG";
FILE *file_out;

int main()
{
    int fd;
    int count = 0;
    char readbuffer[80];
    mkfifo(KLNSPG, 0666);
    fd = open(KLNSPG, 0666);
    file_out = fopen("output.txt", "w");

    if (file_out == NULL)
    {
        printf("Failed! File does not exist!");
        exit(-1);
    }

    if (signal(SIGINT, InterruptHandler) == SIG_ERR)
    {
        printf("Couldnt set the handler to the \"SIGINT\" signal!\n");
        return 0;
    }
    printf("Starting read the texts writing into the pipe:\n");

    while (1)
    {
        read(fd, readbuffer, sizeof(readbuffer));
        count = count + 1;
        fprintf(file_out, "%d. %s\n", count, readbuffer);

        printf("Texts written into the pipe and the file: %s\n", readbuffer);
        sleep(1);
    }
    return 0;
}

void InterruptHandler(int sig)
{
    fclose(file_out);
    if (remove(KLNSPG) == 0)
    {
        printf("\nPipeline deleted!\n");
    }
    else
    {
        printf("\nCannot deleted pipeline!\n");
    }
    exit(0);
}
