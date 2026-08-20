#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int options;
    int itemNummer;
    itemNummer = atoi(optarg);
    while ((options = getopt(argc, argv, "hla:d:")) != -1)
    {

        switch (options)
        {
        case 'h':
            printf("Hilfe wurde abgerufen.\n");
            break;

        case 'l':
            printf("Liste wurde abgerufen.\n");
            break;

        case 'a':
            printf("Neue Aufgabe: %s\n", optarg);
             break;
        case 'd':
            printf("Item zum Löschen: %s\n", optarg);
            break;
        }
    }

    return 0;
}