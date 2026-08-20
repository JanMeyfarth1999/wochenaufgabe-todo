#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

    int options;
    options = getopt(argc, argv, "hl");
    while((options = getopt(argc, argv, "hl"))!= -1)
    {

        if (options == 'h')
        {
            printf("Hilfe wurde abgerufen.\n");
        }
        else if (options == 'l')
        {
            printf("Liste wurde abgerufen ");
        }
    }

    return 0;
}