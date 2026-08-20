#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

    int options;
    options = getopt(argc, argv, "hl");
    if (options == 'h')
    {

        printf("Hilfe wurde abgerufen.");
    }
    else if (options == 'l')
    {
        printf("Liste wurde abgerufen");
    }

    return 0;
}