#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("Es wurde kein Argument eingegeben");

        return 1;
    }
    for (int i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }

    return 0;
}