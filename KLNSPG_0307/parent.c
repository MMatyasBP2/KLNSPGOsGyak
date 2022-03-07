#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main (void) {
    pid_t pid;

    if ((pid = fork()) < 0){
        perror("Process error");
    }
    else if (pid == 0){
        if(execl("./child", "child", (char *) NULL) < 0){
            perror("Execl error");
        }
    }
    if (waitpid(pid, NULL, 0) < 0){
        perror("Wait error");
    }
    return 0;
}