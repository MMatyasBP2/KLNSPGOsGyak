#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define FILE "KLNSPG.txt"

int main() {
    int fileHandle = open(FILE, O_RDWR);
    if(fileHandle == -1)
    {
        perror("Nem sikerult megnyitni a fajlt!");
        return 1;
    } else
        printf("Megnyitottam a fajlt!");
    char tartalom[64];

    int olvasott = read(fileHandle, tartalom, sizeof(tartalom));
    printf("beolvasott tartalom: \"%s\" osszesen \"%i\" byte.\n", tartalom, olvasott);

    lseek(fileHandle, 0, SEEK_SET);

    char szoveg[] = "teszt";
    int irt = write(fileHandle, szoveg, sizeof(szoveg));
    printf("A fajlba irtuk a(z) \"%s\" szoveget. osszesen \"%i\" byte.\n", szoveg, irt);
    close(fileHandle);
    return 0;
}