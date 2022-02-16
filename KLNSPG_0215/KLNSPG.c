#include <stdio.h>
#include <stdlib.h>

#define SIZE 1 << 10

int main()
{
    FILE *file = fopen("vezeteknev.txt", "r");
    fprintf(file, "Martinak Matyas\nProgramtervezo informatikus BSc\nKLNSPG");

    if (file == NULL)
    {
        perror("Unable to open the file!");
        exit(1);
    }

    char lines[SIZE];
    while(fgets(lines, SIZE, file))
    {
        printf("%s", lines);
    }

    fclose(file);

    return 0;
}