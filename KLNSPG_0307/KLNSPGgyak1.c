#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int status = system("ls");;
    printf(status);
}