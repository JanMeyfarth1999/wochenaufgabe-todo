#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int options;
    while ((options = getopt(argc, argv, "hl")) != -1)
    {

        switch (options)
        {
        case 'h':
            printf("Hilfe wurde abgerufen.\n");
            break;
        
        
        
        case 'l':
            printf("Liste wurde abgerufen.\n");
            break;
        }
    }

    return 0;
}