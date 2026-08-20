#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

    int options;
    options = getopt(argc, argv, "h");

    if (options == 'h')
    {
        printf("Hilfe wurde abgerufen");
    }

    return 0;
}
